#include<bits/stdc++.h>
using namespace std;

class fuc1{
	public:
		int t;
		fuc1(){t = 1;}
		void test(fuc1& s);
};

void fuc1::test(fuc1 &s){
	s.t = 123;
}

int main(){
	fuc1 temp,temp1;
	cout << "temp1 : " << temp1.t << "\n";
	temp.test(temp1);
	cout << "temp1 : " << temp1.t << "\n";
	return 0;
} 
