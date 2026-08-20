#include<stdio.h>
#include<iostream>
using namespace std;

//P1776 宝物筛选
const int N = 1e5 + 10;
int dp[N],v[N],w[N];

int main(){
	int n,W,idx = 0,tv,tw,tn;
	cin >> n >> W;
	for(int i = 0;i < n;i++){
		cin >> tv >> tw >> tn;
		int temp = 1;
		//二进制分组 
		while(tn > temp){
			tn -= temp;
			v[++idx] = tv * temp;
			w[idx] = tw * temp;
			temp *= 2;
		}
		v[++idx] = tv * tn;
		w[idx] = tw * tn;
	}
	
	//转化为01背包
	for(int i = 1;i <= idx;i++){
		for(int j = W;j >= w[i];j--){
			if(dp[j] < dp[j - w[i]] + v[i]) dp[j] = dp[j - w[i]] + v[i];
		}
	} 
	
	cout << dp[W] << endl;
	return 0;
}

