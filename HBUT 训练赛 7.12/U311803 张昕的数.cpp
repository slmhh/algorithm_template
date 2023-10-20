#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string.h>
using namespace std;

const int N = 2e5 + 10,mod = 1e9 + 7;
int nums[N] = {0};

long long int gcd(long long int a,long long int b){
	return b == 0 ? a : gcd(b,a % b);
}

int main(){
	long long n,temp; 
	scanf("%lld",&n);
	for(int i = 0;i < n;i++){
		scanf("%lld",&nums[i]);
	} 
	
	sort(nums,nums + n);
	temp = nums[1] - nums[0];
	for(int i = 1;i < n;i++){
		temp = gcd(nums[i]-nums[i - 1],temp);
	}
	if(temp == 1) cout << 2 << endl;
	else cout << 1 << endl;
	return 0;
}
