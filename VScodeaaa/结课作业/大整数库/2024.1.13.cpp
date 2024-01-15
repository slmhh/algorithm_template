#include<bits/stdc++.h>
using namespace std;

class BigInteger{
	private:
		vector<int> num;  //从低位到高位存储每一位数字
	public:
		BigInteger(){};
		BigInteger(string temp){
			for(int i = temp.size() - 1;i >= 0;i--)
				num.push_back(temp[i] - '0');
		}
		BigInteger(long long temp){
			if(temp == 0) num.push_back(0);
			while(temp > 0){
				num.push_back(temp % 10);
				temp /= 10;
			}
		}
		void print();
		bool IsZero();  //判断是否为零
		friend bool operator <= (BigInteger a,BigInteger b);
		friend bool operator == (BigInteger a,BigInteger b);
		friend BigInteger operator + (BigInteger a,BigInteger b); // a + b
		friend BigInteger operator - (BigInteger a,BigInteger b); // a - b
		friend BigInteger operator * (BigInteger a,BigInteger b); // a * b
		friend BigInteger operator / (BigInteger a,BigInteger b); // a / b
		friend BigInteger operator % (BigInteger a,BigInteger b); // a % b
		friend BigInteger gcd(BigInteger a,BigInteger b); //gcd(a,b)
		BigInteger pow(BigInteger b,BigInteger mod); // a ^ b mod p
		BigInteger inv(BigInteger b);  //a * inv(a) ≡ 1 (mod b)
};

void BigInteger::print(){
	for(int i = num.size() - 1;i >= 0;i--)
		cout << num[i];
	cout << "\n";
}

bool BigInteger::IsZero(){
	if(num.size() > 1) return false;
	if(num[0] == 0) return true;
	return false;
}

bool operator <= (BigInteger a,BigInteger b){
	if(a.num.size() != b.num.size())
		return a.num.size() < b.num.size();
	for(int i = a.num.size() - 1;i >= 0;i--){
		if(a.num[i] != b.num[i])
			return a.num[i] < b.num[i];
	}
	return true; 
}

bool operator == (BigInteger a,BigInteger b){
	if(a.num.size() != b.num.size()) return false;
	for(int i = 0;i < a.num.size();i++){
		if(a.num[i] != b.num[i]) return false;
	}
	return true;
}

// a + b
BigInteger operator + (BigInteger a,BigInteger b){
	BigInteger ans;
	int last = 0;
	for(int i = 0;i < a.num.size() || i < b.num.size();i++){
		if(i < a.num.size()) last += a.num[i];
		if(i < b.num.size()) last += b.num[i];
		ans.num.push_back(last % 10);
		last /= 10;
	}
	if(last) ans.num.push_back(last);
	return ans;
}

// a - b
BigInteger operator -(BigInteger a ,BigInteger b){
	BigInteger ans;
	int last = 0;
	for(int i = 0;i < a.num.size();i++){
		last = a.num[i] - last;
		if(i < b.num.size()) last -= b.num[i];
		ans.num.push_back((last + 10) % 10);
		if(last < 0) last = 1;
		else last = 0;
	}
	while(ans.num.size() > 1 && ans.num.back() == 0) //去除前导零
		ans.num.pop_back();  
	return ans;
}

// a * b
BigInteger operator * (BigInteger a,BigInteger b){
	BigInteger ans;
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
	BigInteger ans,tempa = a,tempb = b;
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
	if(a <= b) return a;
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

BigInteger exgcd(BigInteger a,BigInteger b,BigInteger &x,BigInteger &y){
	if(b.IsZero()){
		x = BigInteger(1);
		y = BigInteger(0);
		return a;
	}
	BigInteger gd = exgcd(b,a % b,x,y);
	BigInteger temp = x;
	x = y;
	y = temp - (a / b) * y;
	x.print();
	return gd;
}

BigInteger BigInteger::inv(BigInteger b){
	BigInteger x,y;
	exgcd((*this),b,x,y);
	return (x % b + b) % b;
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

int main(){
	string temp;
	cin >> temp;
	BigInteger a(temp);
	cin >> temp;
	BigInteger b(temp);
	// (a + b).print();
	/*if(a < b) cout << "YES\n";
	else cout << "NO\n";*/
	// (a - b).print();
	// (a * b).print();
	// (a / b).print();
	// (a % b).print();
	// a.pow(b,BigInteger("11112006825558016")).print();
	// gcd(a,b).print();
	BigInteger p(19),q(13);
	rsa_get_key(p,q);
	BigInteger code = encode(b);
	BigInteger flag = decode(code);
	cout << "text is : ";
	b.print();
	cout << "code is : ";
	code.print();
	cout << "flag is : ";
	flag.print();
	d.print();
	return 0;
}