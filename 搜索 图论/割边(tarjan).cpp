#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e5 + 10;

//bri为割边
struct CutBridge{
    vector<ll> dfn,low,fa;
    vector<vector<ll>> edge;
    int n,m,cnt = 0;
    vector<PII> bri;  

    CutBridge(int n,int m){
        edge.resize(n + 2),dfn.resize(n + 1,0),low.resize(n + 1,0);
        fa.resize(n + 1,0);
        this->n = n,this->m = m;
    }

    void add(int a,int b){
        edge[b].push_back(a);
        edge[a].push_back(b);
    }

    void tarjan(int p){
        low[p] = dfn[p] = ++cnt;
        for (auto to : edge[p]){
            if (!dfn[to]){
                fa[to] = p; // 记录父节点
                tarjan(to);
                low[p] = min(low[p], low[to]);
                if (low[to] > dfn[p])
                    bri.emplace_back(p, to);
            }
            else if (fa[p] != to) // 排除父节点
                low[p] = min(low[p], dfn[to]);
        }
    }

    void work(){
        for(int i = 1;i <= n;i++)
            if(!dfn[i])
                tarjan(i);
    }
};

int main(){
    int n,m;
	cin >> n >> m;
    CutBridge g(n,m);
	for(int i=1; i<=m; i++){
		int a,b;
		cin >> a >> b;
		g.add(a,b);
	}
    g.work();
	// for(auto &i : g.bri){
    //     cout << i.first << " " << i.second << "\n";
    // }
    cout << g.bri.size() << "\n";
	return 0;
}

