#include<stdio.h>
using namespace std;

//P1216 [USACO1.5] [IOI1994]Êý×ÖÈý½ÇÐÎ Number Triangles

const int N = 1010;
int tri[N][N] = {0},dp[N][N] = {0};

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j <= i;j++){
			scanf("%d",&tri[i][j]);
		}
	}
	dp[0][0] = tri[0][0];
	for(int i = 0;i < n - 1;i++){
		for(int j = 0;j <= i;j++){
			int temp = dp[i][j] + tri[i + 1][j];
			if(temp > dp[i + 1][j]) dp[i + 1][j] = temp;
			temp = dp[i][j] + tri[i + 1][j + 1];
			if(temp > dp[i + 1][j + 1]) dp[i + 1][j + 1] = temp;
		} 
	}
	int max = dp[n - 1][0];
	for(int i = 1;i < n;i++){
		if(max < dp[n - 1][i]) max = dp[n - 1][i];
	}
	printf("%d\n",max);
	return 0;
}
