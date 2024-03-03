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
