#include<stdio.h>
#include<iostream>
using namespace std;

//P1616 疯狂的采药
const int N = 1e5 + 10;
int w[N],v[N],dp[N] = {0};

int main(){
	int n,m;
	cin >> m >> n;
	for(int i = 1;i <= n;i++) cin >> w[i] >> v[i];
	for(int i = 1;i <= n;i++){
		//正向遍历，使得每次的wi,被w2i更新过 
		for(int j = w[i]; j <= m;j++){
			//dp[j]为不放物品i的最大价值
			//dp[j - w[j]] 为放了物品i之后的最大价值
			if(dp[j] < dp[j - w[i]] + v[i])
				dp[j] = dp[j - w[i]] + v[i];
		}
	}
	cout << dp[m] << endl;
	return 0;
}

