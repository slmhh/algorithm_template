#include<bits/stdc++.h>
using i64 = long long;

struct HLD{
	std::vector<std::vector<int>> edge;
	std::vector<int> fa,dep,son,siz,top,dfn;
	int cnt,root;
	HLD(){};
	HLD(int n,int r = 1):edge(n + 1),fa(n + 1),dep(n + 1),
						 son(n + 1),siz(n + 1),top(n + 1),
						 dfn(n + 1),cnt(0),root(r){};
	void addEdge(int u,int v){
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	void dfs1(int p){
		dep[p] = dep[fa[p]] + 1,siz[p] = 1;
		for(auto v : edge[p]){
			if(v == fa[p]) continue;
			fa[v] = p;
			dfs1(v);
			siz[p] += siz[v];
			if(siz[v] > siz[son[p]]) son[p] = v;
		}
	}
	void dfs2(int p,int t){
		dfn[p] = ++cnt,top[p] = t;
		if(son[p]) dfs2(son[p],t);
		for(auto v : edge[p]){
			if(v == fa[p] || v == son[p]) continue;
			dfs2(v,v);
		}
	}
	int lca(int u,int v){
		while(top[u] != top[v]){
			if(dep[top[u]] > dep[top[v]]) u = fa[top[u]];
			else v = fa[top[v]];
		}
		if(dep[u] >= dep[v]) return v;
		return u;
	}
	void work(){
		dfs1(root);
    	dfs2(root,root);
	}
};


int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int n,m,s,u,v;
    std::cin >> n >> m >> s;
	HLD t(n,s);
    for(int i = 0;i < n - 1;i++){
        std::cin >> u >> v;
        t.addEdge(u,v);
    }
    t.work();
    while(m--){
        std::cin >> u >> v;
        std::cout << t.lca(u,v) << "\n";
    }
	return 0;
}
 