#include<stdio.h>
#include<iostream>
using namespace std;

//P1757 通天之分组背包
const int N = 1005;
int w[N],v[N],cnt[N] = {0},t[N][N] = {0},dp[N] = {0}; //w重量,v价值,cnt每组数量,t每个物品
 

int main(){
	int n,m,z,ts = 0; 
	cin >> m >> n;
	for(int i = 1;i <= n;i++){
		cin >> w[i] >> v[i] >> z;
		if(z > ts) ts = z; 
		cnt[z]++;
		t[z][cnt[z]] = i;
	}
	
	for(int i = 1;i <= ts;i++)				// 循环每一组
		for(int j = m;j >= 0;j--)			// 循环背包容量
			for(int k = 1;k <= cnt[i];k++)  // 循环该组的每一个物品
				if(j >= w[t[i][k]] && dp[j] < dp[j - w[t[i][k]]] + v[t[i][k]])  // 背包容量充足
					dp[j] = dp[j - w[t[i][k]]] + v[t[i][k]];
				
	cout << dp[m] << "\n";
	return 0;
}

