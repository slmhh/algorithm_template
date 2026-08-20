#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct DSU{
    vector<ll> p;
    DSU(){};
    DSU(int n){
        init(n);
    }

    void init(int n){
        p.resize(n + 1);
        for(int i = 1;i <= n;i++)
            p[i] = i;
    }

    ll find(ll x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void merge(ll x,ll y){
        x = find(x);
        y = find(y);
        p[y] = x;
    }

    bool same(ll x,ll y){
        return find(x) == find(y);
    }
};


struct node{
    ll u,v,w;
};

bool cmp(node a,node b){
    return a.w < b.w;
}
//tr 为输出方案
struct kruskal{
    vector<node> edge,tr;
    DSU d;
    int n,m;
    kruskal(int n,int m){
        this->n = n;
        this->m = m;
        d.init(n);
    }

    void add(ll u,ll v,ll w){
        edge.push_back({u,v,w});
    }

    void work(){
        sort(edge.begin(),edge.end(),cmp);
        for(int i = 0;i < m;i++){
            auto &[u,v,w] = edge[i];
            if(!d.same(u,v)){
                d.merge(u,v);
                tr.push_back({u,v,w});
            }
        }
    }
};


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m,ans = 0;
    cin >> n >> m;
    kruskal k(n,m);
    for(int i = 0;i < m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        k.add(u,v,w);
    }
    
    k.work();
    ll temp = k.d.find(1);
    bool flag = true;
    for(auto &i : k.tr){
        ans += i.w;
    }
    for(int i = 2;i <= n;i++){
        if(k.d.find(i) != temp){
            flag = false;
            break;
        } 
    }
    if(flag) cout << ans << "\n";
    else cout << "orz\n";
    return 0;
}