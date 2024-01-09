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
		void print();
		friend bool operator < (BigInteger &a,BigInteger &b);
		friend BigInteger operator + (BigInteger &a,BigInteger &b);
		friend BigInteger operator - (BigInteger &a,BigInteger &b);
		friend BigInteger operator * (BigInteger &a,BigInteger &b);
};

void BigInteger::print(){
	for(int i = num.size() - 1;i >= 0;i--)
		cout << num[i];
}

bool operator < (BigInteger &a,BigInteger &b){
	if(a.num.size() != b.num.size())
		return a.num.size() < b.num.size();

	for(int i = a.num.size() - 1;i >= 0;i--){
		if(a.num[i] != b.num[i])
			return a.num[i] < b.num[i];
	}
	return false; 
}

BigInteger operator + (BigInteger &a,BigInteger &b){
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

BigInteger operator - (BigInteger &a,BigInteger &b){
	BigInteger ans;
	int last = 0;
	for(int i = 0;i < a.num.size();i++){
		last = a.num[i] - last;
		if(i < b.num.size()) last -= b.num[i];
		ans.num.push_back((last + 10) % 10);
		if(last < 0) last = 1;
		else last = 0;
	}
	while(ans.num.size() > 1 && ans.num[ans.num.size() - 1] == 0)
		ans.num.pop_back();  //去除前导零
	return ans;
}

BigInteger operator * (BigInteger &a,BigInteger &b){
	
}

int main(){
	string temp;
	cin >> temp;
	BigInteger a(temp);
	cin >> temp;
	BigInteger b(temp);
	//(a + b).print();
	/*if(a < b) cout << "YES\n";
	else cout << "NO\n";*/
	//(a - b).print();
	return 0;
}


