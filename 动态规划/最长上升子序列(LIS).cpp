#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e5 + 10;

//B3637 最长上升子序列
//LIS：Longest Increasing Subsequence，最长递增子序列
//树状数组+离散化 O(nlog n)
ll nums[N],tr[N];
map<ll,ll> m;
void update(ll p,ll x){
    for(int i = p;i <= N;i += i & -i)
        tr[i] = max(tr[i],x);
}

ll query(ll p){
    ll res = 0;
    for(int i = p;i >= 1;i -= i & -i)
        res = max(res,tr[i]);
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> nums[i];
        m[nums[i]] = 1;
    }
    ll cnt = 1;
    for(auto i : m){
        m[i.first] = cnt;
        cnt++;
    }
    for(int i = 1;i <= n;i++){
        ll x = query(m[nums[i]] - 1) + 1;
        ans= max(ans,x);
        update(m[nums[i]],x);
    }
    cout << ans << "\n";
    return 0;
}

//动态规划O(n^2) 
/*
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
}*/

