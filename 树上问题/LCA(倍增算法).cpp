#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
vector<int> edge[N];
ll fa[N][25],LOG2[N],dep[N];

void dfs(ll p,ll f){
    fa[p][0] = f;
    dep[p] = dep[f] + 1;
    for(int i = 1;i <= LOG2[dep[p]];i++){
        fa[p][i] = fa[fa[p][i - 1]][i - 1];
    }
    for(auto v : edge[p]){
        if(v == f) continue;
        dfs(v,p);
    }
}

int lca(int u,int v){
    if(dep[u] > dep[v]) swap(u,v);
    while(dep[u] < dep[v]){
        v = fa[v][LOG2[dep[v] - dep[u]]];
    }  
    if(u == v) return u;
    for(int k = LOG2[dep[v]];k >= 0;k--){
        if(fa[u][k] != fa[v][k]){
            v = fa[v][k],u = fa[u][k];
        }
    }
    return fa[u][0];
}


int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m,r;
    cin >> n >> m >> r;
    LOG2[1] = 0;
    for(int i = 2;i <= n;i++){
        LOG2[i] = LOG2[i / 2] + 1;
    }
    for(int i = 1;i < n;i++){
        ll u,v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }    
    dfs(r,r);

    while(m--){
        ll u,v;
        cin >> u >> v;
        cout << lca(u,v) << "\n";
    }

    return 0;
}