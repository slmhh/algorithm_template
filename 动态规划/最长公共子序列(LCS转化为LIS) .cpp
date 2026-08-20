#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

//P1439 【模板】最长公共子序列
//LCS：Longest Common Subsequence，最长公共子序列
typedef long long ll;
const int N = 1e5 + 10;

ll b[N],a[N],tr[N];
void update(ll p,ll x){
    for(int i = p;i <= N;i += i & -i)
        tr[i] = max(tr[i],x);
}

ll query(ll p){
    ll res = 0;
    for(int i = p;i >= 1;i -= i & -i)
        res = max(tr[i],res);
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,t,ans = 1;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> t;
        a[t] = i;
    }
    for(int i = 1;i <= n;i++){
        cin >> t;
        b[i] = a[t];
    }
    for(int i = 1;i <= n;i++){
        ll x = query(b[i] - 1) + 1;
        ans = max(ans,x);
        update(b[i],x);
    }
    cout << ans << "\n";
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 3e3 + 10,mod = 1e9 + 7;

ll dp[N][N],n,m;
PII pre[N][N],temp;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a,b,ans = "";
	cin >> a >> b;
	n = a.size(),m = b.size();
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				pre[i][j] = {i - 1,j - 1};
			}
			else{
				if(dp[i - 1][j] >= dp[i][j - 1]){
					dp[i][j] = dp[i - 1][j];
					pre[i][j] = {i - 1,j};
				}
				else{
					dp[i][j] = dp[i][j - 1];
					pre[i][j] = {i,j - 1};
				}
			}
		}
	}
	ll x = n,y = m;
	while(dp[x][y] != 0){
		if(a[x - 1] == b[y - 1]) ans += a[x - 1];
		temp = pre[x][y];
		x = temp.first,y = temp.second;
	}
	reverse(ans.begin(),ans.end());
	cout << ans << "\n";
	return 0;
}
*/
