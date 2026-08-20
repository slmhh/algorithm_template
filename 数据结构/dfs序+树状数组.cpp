#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

//https://ac.nowcoder.com/acm/contest/27836/C
typedef int ll;
typedef pair<ll,ll> PII;
const int N = 1e6 + 10,mod = 1e9 + 7;

ll tr[N],out[N],in[N],n,m,k,op,t,u,v,a[N];
vector<ll> edge[N];
void update(ll p,ll x){
    for(int i = p;i < n + 5;i += i & -i)
        tr[i] += x;
}

ll getsum(ll p){
    ll res = 0;
    for(int i = p;i >= 1;i -= i & -i)
        res += tr[i];
    return res;
}

ll cnt = 0;
void dfs(ll p,ll fa){
    in[p] = ++cnt;
    for(auto i : edge[p]){
        if(i != fa) dfs(i,p);
    }
    out[p] = cnt;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n - 1;i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(k,-1);
    for(int i = 1;i <= n;i++){
        update(in[i],a[i]);
    }
    while(m--){
        cin >> op >> t;
        if(op == 1){
            cin >> u;
            update(in[t],u);
        }
        else{
            cout << getsum(out[t]) - getsum(in[t] - 1)<< "\n";
        }
    }
	return 0;
}
