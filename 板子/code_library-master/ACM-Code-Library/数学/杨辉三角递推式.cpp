#include<iostream>
#include<string.h>
using namespace std;

//P5461 ÉâÃâÕ½·ý
const int N = 1e4 + 10;
long long int a[N] = {0};

int main(){
	int n;
	cin >> n;
	a[1] = 1;
	for(int j = 1;j <= (1 << n);j++){
		for(int i = 1;i <= (1 << n) - j;i++) cout << "0 ";
		for(int i = j;i >= 1;i--){
			a[i] += a[i - 1];
			cout << (a[i] % 2 == 0 ? "0" : "1") << " ";
		}
		cout << endl;
	}
	return 0;
}
