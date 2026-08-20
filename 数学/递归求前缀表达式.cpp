#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int i = 0;
double Evalue(const string &exp){
	char e[100];
	e[0] = exp[i++];
	switch(e[0]){
		case '+': return Evalue(exp) + Evalue(exp);
		case '-': return Evalue(exp) - Evalue(exp);
		case '*': return Evalue(exp) * Evalue(exp);
		case '/': return Evalue(exp) / Evalue(exp);
		default: return atof(e); break;  //转化字符串为浮点数 
	}
}

int main(){
	string exp;
	getline(cin,exp);
	cout << Evalue(exp) << endl;
	return 0;
}
