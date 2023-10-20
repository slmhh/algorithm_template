#include<stdio.h>
#include<iostream>
using namespace std;

//P2871 [USACO07DEC] Charm Bracelet S
const int N = 1e5 + 10;
int w[N],v[N],dp[N] = {0};

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> w[i] >> v[i];
	for(int i = 1;i <= n;i++){
		for(int j = m;j >= w[i];j--){
			//dp[j]为不放物品i的最大价值
			//dp[j - w[j]] 为放了物品i之后的最大价值
			if(dp[j] < dp[j - w[i]] + v[i])
				dp[j] = dp[j - w[i]] + v[i];
		}
	}
	cout << dp[m] << endl;
	return 0;
}

