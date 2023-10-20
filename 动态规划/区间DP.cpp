#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

//P1775 石子合并（弱化版）
//状态 f(i,j) 表示将下标位置 i 到 j 的所有元素合并能获得的价值的最值
const int N = 610;
int w[N],sum[N] = {0},dp[N][N] = {0};

int main(){
	long long int n;
	cin >> n;
	memset(dp,0x3f,sizeof(dp));
	for(int i = 1;i <= n;i++){
		cin >> w[i];
		dp[i][i] = 0;
	}
	sum[1] = w[1];
	for(int i = 2;i <= n;i++) sum[i] = w[i] + sum[i - 1];
	for(int i = 1;i <= n;i++) sum[i + n] = sum[i + n - 1] + w[i];
	
	// 遍历每种区间长度
	for(int len = 2;len <= n;len++){
		// 遍历每个区间的起始位置
		for(int i = 1;i <= 2 * n - 1 - len;i++){
			int j = len + i - 1;// 区间的终止位置
			// 遍历区间内的每个位置，找到最大得分和最小得分
			for(int k = i;k < j;k++){
				if(dp[i][j] > dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]) dp[i][j] = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
			}
		}
	}
	
	/*for(int i = 1;i <= 2 * n;i++){
		for(int j = 0;j <= 2 * n;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	cout << dp[1][n] << endl;
	return 0;
}

