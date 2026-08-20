#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class BigInteger{
	private:
		vector<int> num;
		int len;
	public:
		BigInteger(){num.clear(),len = 0;};
		BigInteger(string temp){
			len = temp.size();
			for(int i = temp.size() - 1;i >= 0;i--)
				num.push_back(temp[i] - '0');
		};
		void print();
		friend BigInteger operator+(BigInteger &a,BigInteger &b);
};

void BigInteger::print(){
	for(int i = len - 1;i >= 0;i--)
		cout << num[i];
}

BigInteger operator+(BigInteger &a,BigInteger &b){
	BigInteger ans;
	int temp,i = 0,last = 0;
	for(;i < a.len || i < b.len;i++){
		if(i < a.len) last += a.num[i];
		if(i < b.len) last += b.num[i];
		ans.num.push_back(last % 10);
		ans.len++;
		last /= 10;
	}
	if(last){
		ans.num.push_back(last);
		ans.len++;
	}
	return ans;
}

int main(){
	string temp;
	cin >> temp;
	BigInteger a(temp);
	cin >> temp;
	BigInteger b(temp);
	(a + b).print();
	return 0;
}


