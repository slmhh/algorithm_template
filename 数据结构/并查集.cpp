#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU{
    std::vector<int> p,siz;
    DSU ();
    DSU(int n){init(n);};

    void init(int n){
        p.assign(n + 1,0);
        siz.assign(n + 1,1);
        std::iota(p.begin(),p.end(),0);
    }

    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    bool merge(int x,int y){
        int u = find(x),v = find(y);
        if(u == v) return false;
        if(siz[u] <= siz[v]){
            p[u] = v;
            siz[v] += siz[u];
        }
        else{
            p[v] = u;
            siz[u] += siz[v];
        }
        return true;
    }

    int get_id(int x){
        return find(x);
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,q;
    cin >> n >> q;
    DSU d(2 * n); 
    while(q--){
        char op;
        ll x,y;
        cin >> op >> x >> y;
        if(op == 'F'){
            d.merge(x,y);
        }
        else{
            d.merge(x,y + n);
            d.merge(y,x + n);
        }
    }
    ll cnt = 0;
    for(int i = 1;i <= n;i++){
        if(d.find(i) == i) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}