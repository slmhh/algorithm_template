#include<bits/stdc++.h>
using i64 = long long;

//Centroid Decomposition O(NlogN)
struct CD{
	std::vector<std::vector<std::array<int,2>>> edge;
	std::vector<int> siz,del,dp,stk,dep,ask,ans;
	int cnt = 0,root,n,m;
	CD(){};
	CD(int _n,int _m):edge(_n + 1),siz(_n + 1),del(_n + 1),dp(_n + 1),
					dep(_n + 1),ask(_m + 1),ans(_m + 1),n(_n),m(_m){dp[0] = 2e9;}
	void addEdge(int u,int v,int w){
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	void getSize(int p,int f = 0){
		siz[p] = 1,cnt++;
		for(auto [v,_] : edge[p]){
			if(v == f || del[v]) continue;
			getSize(v,p);
			siz[p] += siz[v];
		}
	}
	void getRoot(int p,int f = 0){
		dp[p] = cnt - siz[p];
		for(auto [v,_] : edge[p]){
			if(v == f || del[v]) continue;
			getRoot(v,p);
			dp[p] = std::max(dp[p],siz[v]);
		}
		if(dp[p] < dp[root]) root = p;
	}
	void getDist(int p,int f = 0){
		stk.push_back(dep[p]);
		for(auto [v,w] : edge[p]){
			if(v == f || del[v]) continue;
			dep[v] = dep[p] + w;
			getDist(v,p);
		}
	}
	void calc(int u){
		cnt = 0,getSize(u);
		root = 0,getRoot(u);
		del[root] = 1;
		std::unordered_set<int> st;
		st.insert(0);
		for(auto [v,w] : edge[root]){
			if(del[v]) continue;
			dep[v] = w,getDist(v);
			for(int i = 1;i <= m;i++){
				for(auto len : stk){
					if(st.count(ask[i] - len))
						ans[i] = 1;
				}
			}
			while(!stk.empty()){
				st.insert(stk.back());
				stk.pop_back();
			}
		}
		for(auto [v,_] : edge[root]){
			if(del[v]) continue;
			calc(v);
		}
	}
};

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0); 
	int n,m;
	std::cin >> n >> m;
	CD t(n,m);
	for(int i = 1;i < n;i++){
		int u,v,w;
		std::cin >> u >> v >> w;
		t.addEdge(u,v,w);
	}
	for(int i = 1;i <= m;i++) std::cin >> t.ask[i];
	t.calc(1);
	for(int i = 1;i <= m;i++){
		if(t.ans[i]) std::cout << "AYE\n";
		else std::cout << "NAY\n";
	}
	return 0;
}