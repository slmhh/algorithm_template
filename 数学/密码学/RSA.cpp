#include<iostream>
#include<string>
using namespace std;

class BigNumber{
	private:
		string num;
	public:
		BigNumber(){num = "";}
		BigNumber(string str)(num = str;)
		BigNumber operator + (BigNumber& a,BigNumber& b);
		BigNumber operator - (BigNumber& a,BigNumber& b); 
		BigNumber operator * (BigNumber& a,BigNumber& b); 
		BigNumber operator / (BigNumber& a,BigNumber& b);  
};

BigNumber operator + (BigNumber& a,BigNumber& b){
	
}

int main(){
	string a;
	return 0;
}
