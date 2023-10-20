#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;

const int N = 1e5 + 10,mod = 1e9 + 7;
long long int a[N] = {0},dp[N] = {0};

int main(){
	long long int n,k,i,j,l;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	
	
	for(i = 1;i <= n;i++){
		j = a[i] > k ? k : a[i];
		for(;j > a[i - 1];j--){
			for(l =j - a[i] + a[i - 1];l < j;l++){
				if(dp[l] == 0) dp[j]++;
				else dp[j] = (dp[j] + dp[l] % mod) % mod; 
			}
		}
		for(int s = 0;s <= k;s++) cout << dp[s] << " ";
		cout << endl;
	}
	
	cout << dp[k] % mod << endl;
	return 0;
}
