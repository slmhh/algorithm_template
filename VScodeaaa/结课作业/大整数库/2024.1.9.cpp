#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class BigInteger{
	private:
		vector<int> num;  //从低位到高位存储每一位数字
	public:
		BigInteger(){};
		BigInteger(string temp){
			for(int i = temp.size() - 1;i >= 0;i--)
				num.push_back(temp[i] - '0');
		};
		BigInteger(int temp){
			while(temp > 0){
				num.push_back(temp % 10);
				temp /= 10;
			}
		};
		void print();
		friend bool operator <= (BigInteger a,BigInteger b);
		friend bool operator == (BigInteger a,BigInteger b);
		friend BigInteger operator + (BigInteger a,BigInteger b); // a + b
		friend BigInteger operator - (BigInteger a,BigInteger b); // a - b
		friend BigInteger operator * (BigInteger a,BigInteger b); // a * b
		friend BigInteger operator / (BigInteger a,BigInteger b); // a / b
		friend BigInteger operator % (BigInteger a,BigInteger b); // a % b
		BigInteger pow(BigInteger b,BigInteger mod); // a ^ b mod pz
};

void BigInteger::print(){
	for(int i = num.size() - 1;i >= 0;i--)
		cout << num[i];
	cout << "\n";
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
	if(last){
		ans.num.push_back(last);
	}
	return ans;
}

// a - b
BigInteger operator - (BigInteger a,BigInteger b){
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
	while(ans.num.size() > 1 && ans.num.back() == 0) //去除前导零
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
	while(ans.num.size() > 1 && ans.num.back() == 0) //去除前导零
		ans.num.pop_back();
	return ans;
}

// a % b
BigInteger operator % (BigInteger a,BigInteger b){
	return a - b * (a / b);
}

// a ^ b mod p
BigInteger BigInteger::pow(BigInteger b,BigInteger mod){
	if(b == BigInteger(0)) return BigInteger(1);
	if(b == BigInteger(1)) return (*this) % mod;
	BigInteger temp = (*this).pow(b / BigInteger(2),mod) % mod;
	if(b.num[0] % 2 == 0) return (temp * temp) % mod;
	return (((temp * temp) % mod) * (*this)) % mod;
}

int main(){
	string temp;
	cin >> temp;
	BigInteger a(temp);
	cin >> temp;
	BigInteger b(temp);
	(a + b).print();
	/*if(a < b) cout << "YES\n";
	else cout << "NO\n";*/
	(a - b).print();
	(a * b).print();
	(a / b).print();
	(a % b).print();
	return 0;
}


