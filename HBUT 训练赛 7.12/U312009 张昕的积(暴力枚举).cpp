#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
//[ABC296D] M<=ab

int main(){
	long long int n,m,ans = 1e18,a,b;
	cin >> n >> m;
	for(a = 1;a <= n;a++){
		b = ceil(m * 1.0 / a); //(m - 1) / a + 1
		if(b < a) break;
		if(b <= n) ans = ans < b * a ? ans : b * a; 
	}
	cout << (ans == 1e18 ? -1 : ans) << endl;
	return 0;
}
