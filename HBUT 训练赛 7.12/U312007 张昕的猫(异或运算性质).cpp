#include<iostream>
using namespace std;

const int N = 1e6 + 10;
long long int a[N];

int main(){
	long long n,ans;
	cin >> n;
	cin >> a[0];
	ans = a[0];
	for(int i = 1;i < n;i++){
		cin >> a[i];
		ans = ans ^ a[i];
	}
	for(int i = 0;i < n;i++){
		cout << (a[i] ^ ans) << " ";
	}
	return 0;
}
