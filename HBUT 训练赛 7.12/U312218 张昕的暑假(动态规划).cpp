#include<iostream>
using namespace std;

const int N = 1e5 + 10;
long long int g[N][3],dp[N][3] = {0};

int main(){
	long long n,max = 0;
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld %lld %lld",&g[i][0],&g[i][1],&g[i][2]);
	}
	
	for(int i = 1;i <= n;i++){  //每天 
		for(int j = 0;j < 3;j++){  //当天每个项目 
			for(int k = 0;k < 3;k++){  //前一天每个项目 
				if(k != j && dp[i - 1][k] + g[i][j] > dp[i][j]){
					dp[i][j] = dp[i - 1][k] + g[i][j];
				}
			}
		}
	}
	
	for(int i = 0;i < 3;i++){
		if(max <= dp[n][i]) max = dp[n][i];
	}
	
	printf("%lld\n",max);
	return 0;
}
