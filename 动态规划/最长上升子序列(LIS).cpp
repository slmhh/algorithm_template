#include<stdio.h>
#include<iostream>
using namespace std;

//B3637 最长上升子序列
//LIS：Longest Increasing Subsequence，最长递增子序列
const int N = 1e5 + 10;
long long nums[N],dp[N] = {0};

int main(){
	long long n,max = 0;
	scanf("%lld",&n);
	for(int i = 0;i < n;i++) scanf("%lld",&nums[i]);
	

	for(int i = 0;i < n;i++){
		dp[i] = 1;
		for(int j = 0;j < i;j++){
			if(nums[j] < nums[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
		}
		if(max < dp[i]) max = dp[i];
	}
	
	cout << max << endl;
	return 0;
}

