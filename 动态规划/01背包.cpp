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

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;

PII nums[N];
ll bag[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,V,v,w;
    cin >> n >> V;
    for(int i = 1;i <= n;i++){
        cin >> v >> w;
        nums[i] = {v,w};
    }
    //第一问背包可以装的最大价值
    for(int i = 1;i <= n;i++)
        for(int j = V;j >= nums[i].first;j--)
            bag[j] = max(bag[j],bag[j - nums[i].first] + nums[i].second);

    cout << bag[V] << "\n";
    
    //第二问刚好装满时的最大价值
    memset(bag,-0x3f3f3f3f,sizeof(bag));
    bag[0] = 0;
    for(int i = 1;i <= n;i++)
        for(int j = V;j >= nums[i].first;j--)
            bag[j] = max(bag[j],bag[j - nums[i].first] + nums[i].second);

    cout << max(0LL,bag[V]) << "\n";
    return 0;
}
*/
