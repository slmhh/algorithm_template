#include<iostream>
#include<vector>
using namespace std;

class BigInteger {
private:
	vector<int> num;  //从低位到高位存储每一位数字
	bool sign;        //符号位
public:
	BigInteger() { sign = false; };
	BigInteger(bool s, BigInteger t) : sign(s), num(t.num) {};
	BigInteger(string temp) {
		sign = false;
		if (temp[0] == '-') {
			sign = true;
			temp.erase(temp.begin());
		}
		for (int i = temp.size() - 1; i >= 0; i--)
			num.push_back(temp[i] - '0');
	}
	BigInteger(int temp) {
		sign = false;
		if(temp == 0) num.push_back(0);
		if (temp < 0) {
			sign = true;
			temp = -temp;
		}
		while (temp > 0) {
			num.push_back(temp % 10);
			temp /= 10;
		}
	}
	void print();
	bool IsZero();  //判断是否为零
	friend bool operator <= (BigInteger a, BigInteger b);
	friend bool operator == (BigInteger a, BigInteger b);
	friend bool operator < (BigInteger a, BigInteger b){return (a <= b && !(a == b));};
	BigInteger operator + () const { return *this; }  // +a
	BigInteger operator - () const { return BigInteger(!sign, *this); } // -a
	friend BigInteger operator + (BigInteger a, BigInteger b); // a + b
	BigInteger add(BigInteger b);
	friend BigInteger operator - (BigInteger a, BigInteger b); // a - b
	BigInteger sub(BigInteger b);
	friend BigInteger operator * (BigInteger a, BigInteger b); // a * b
	friend BigInteger operator / (BigInteger a, BigInteger b); // a / b
	friend BigInteger operator % (BigInteger a, BigInteger b); // a % b
	BigInteger pow(BigInteger b, BigInteger mod); // a ^ b mod p
	BigInteger abs() { return BigInteger(true,*this); }
	BigInteger inv(BigInteger mod);
};

void BigInteger::print() {
	if(IsZero()){
		cout << "0\n";
		return;
	}
	if (sign) cout << '-';
	for (int i = num.size() - 1; i >= 0; i--)
		cout << num[i];
	cout << "\n";
}

bool BigInteger::IsZero() {
	if (num.size() > 1) return false;
	if (num[0] == 0) return true;
	return false;
}

bool operator <= (BigInteger a, BigInteger b) {
	if(a.sign ^ b.sign) return a.sign;
	if (a.num.size() != b.num.size())
		return a.num.size() < b.num.size();
	for (int i = a.num.size() - 1; i >= 0; i--) {
		if (a.num[i] != b.num[i])
			return a.num[i] < b.num[i];
	}
	return true;
}

bool operator == (BigInteger a, BigInteger b) {
	if (a.sign != b.sign) return false;
	if (a.num.size() != b.num.size()) return false;
	for (int i = 0; i < a.num.size(); i++) {
		if (a.num[i] != b.num[i]) return false;
	}
	return true;
}

// a + b
BigInteger BigInteger::add(BigInteger b) {
	BigInteger ans;
	int last = 0;
	for (int i = 0; i < num.size() || i < b.num.size(); i++) {
		if (i < num.size()) last += num[i];
		if (i < b.num.size()) last += b.num[i];
		ans.num.push_back(last % 10);
		last /= 10;
	}
	if (last) ans.num.push_back(last);
	return ans;
}

BigInteger operator + (BigInteger a, BigInteger b) {
	if(a.sign ^ b.sign){
		if(a.sign) return b.sub(a);
		else return a.sub(b);
	}
	return BigInteger(a.sign,a.add(b));
}

// a - b
BigInteger BigInteger::sub(BigInteger b){
	if(abs() < b.abs()) return BigInteger(true,b.sub(*this));
	BigInteger ans;
	int last = 0;
	for (int i = 0; i < num.size(); i++) {
		last = num[i] - last;
		if (i < b.num.size()) last -= b.num[i];
		ans.num.push_back((last + 10) % 10);
		if (last < 0) last = 1;
		else last = 0;
	}
	while (ans.num.size() > 1 && ans.num.back() == 0) //去除前导零
		ans.num.pop_back();
	return ans;
}

BigInteger operator - (BigInteger a, BigInteger b){
	if(a.sign ^ b.sign) return BigInteger(a.sign,a.add(b));
	if(a.sign) return b.sub(a);
	return a.sub(b); 
}

// a * b
BigInteger operator * (BigInteger a,BigInteger b){
	BigInteger ans;
	if(a.sign ^ b.sign) ans.sign = true;
	ans.num.resize(a.num.size() + b.num.size(),0);
	for(int i = 0;i < b.num.size();i++){
		int temp = 0;
		for(int j = 0;j < a.num.size() || temp;j++){
			if(j < a.num.size()) temp += a.num[j] * b.num[i] + ans.num[i + j];
			ans.num[i + j] = temp % 10;
			temp /= 10;
		}
	}
	while(ans.num.size() > 1 && ans.num.back() == 0)
		ans.num.pop_back();
	return ans;
}

// a / b
BigInteger operator / (BigInteger a,BigInteger b){
	if(a.abs() < b.abs()) return BigInteger(0);
	BigInteger ans,tempa = a.abs(),tempb = b.abs();
	if(a.sign ^ b.sign) ans.sign = true;
	int move = a.num.size() - b.num.size();
	ans.num.resize(move + 1,0);
	tempb.num.insert(tempb.num.begin(),move,0);
	for(int i = move;i >= 0;i--){
		int left = 0,right = 11;
		while(left + 1 < right){   //二分法求商
			int mid = (left + right) >> 1;
			if(tempb * BigInteger(mid) <= tempa) left = mid;
			else right = mid;
		}
		ans.num[i] = left;
		tempa = tempa - tempb * BigInteger(left);
		tempb.num.erase(tempb.num.begin());
	}
	while(ans.num.size() > 1 && ans.num.back() == 0)
		ans.num.pop_back();
	return ans;
}

// a % b
BigInteger operator % (BigInteger a,BigInteger b){
	if(a == b) return BigInteger(0);
	return a - b * (a / b);
}

// a ^ b mod p
BigInteger BigInteger::pow(BigInteger b,BigInteger mod){
	if(b.IsZero()) return BigInteger(1);
	if(b == BigInteger(1)) return (*this) % mod;
	BigInteger temp = (*this).pow(b / BigInteger(2),mod) % mod;
	if(b.num[0] % 2 == 0) return (temp * temp) % mod;
	return (((temp * temp) % mod) * (*this)) % mod;
}

//gcd(a,b)
BigInteger gcd(BigInteger a,BigInteger b){
	if(a == b) return a;
	if(a <= b) return gcd(b,a);
	if(b.IsZero()) return a;
	return gcd(b,a % b);
}

//ax + by = 1
BigInteger exgcd(BigInteger a,BigInteger b,BigInteger &x,BigInteger &y){
	if(b.IsZero()){
		x = BigInteger(1);
		y = BigInteger(0);
		return a;
	}
	BigInteger d = exgcd(b,a % b,x,y);
	BigInteger temp = x;
	x = y;
	y = temp - (a / b) * y;
	return d;
}

BigInteger BigInteger::inv(BigInteger mod){
	BigInteger x,y;
	exgcd((*this),mod,x,y);
	return (x % mod + mod) % mod;
}

//(n,e)公钥，(n,d)私钥
BigInteger d,n,phi,e(65537);
void rsa_get_key(BigInteger p,BigInteger q){
	n = p * q;
	phi = (p - BigInteger(1)) * (q - BigInteger(1));
	d = e.inv(phi);
}

BigInteger encode(BigInteger text){
	return text.pow(e,n);
}

BigInteger decode(BigInteger code){
	return code.pow(d,n);
}


int main() {
	string temp;
	// cin >> temp;
	// BigInteger a(temp);
	cin >> temp;
	BigInteger b(temp);
	// a.print();
	// b.print();
	// (a + b).print();
	// if(a.abs() < b.abs()) cout << "YES\n";
	// else cout << "NO\n";
	// (a - b).print();
	// (a * b).print();
	// (a / b).print();
	// (a % b).print();
	// a.inv(b).print();
	BigInteger p("33478071698956898786044169848212690817704794983713768568912431388982883793878002287614711652531743087737814467999489");
	BigInteger q("36746043666799590428244633799627952632279158164343087642676032283815739666511279233373417143396810270092798736308917");
	rsa_get_key(p,q);
	BigInteger code = encode(b);
	BigInteger flag = decode(code);
	cout << "text is : ";
	b.print();
	cout << "code is : ";
	code.print();
	cout << "flag is : ";
	flag.print();
	return 0;
}