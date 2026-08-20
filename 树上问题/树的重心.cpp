#include<bits/stdc++.h>
using i64 = long long;

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0); 
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> edge(n + 1);
	for(int i = 1;i < n;i++){
		int u,v;
		std::cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	std::vector<int> dp(n + 1),siz(n + 1,1);
	std::array<int,2> ans{};
	auto dfs = [&](auto&&self,int p,int f) -> void{
		for(auto v : edge[p]){
			if(v == f) continue;
			self(self,v,p);
			siz[p] += siz[v];
			dp[p] = std::max(dp[p],siz[v]);
		}
		dp[p] = std::max(dp[p],n - siz[p]);
		if(ans[0] == 0) ans[0] = p;
		else if(dp[p] < dp[ans[0]]) ans = {p,0};
		else if(dp[p] == dp[ans[0]]) ans[1] = p;
	};
	dfs(dfs,1,0);
	if(ans[1] == 0) std::cout << ans[0] << "\n";
	else{
		if(ans[1] < ans[0]) std::swap(ans[1],ans[0]);
		std::cout << ans[0] << " " << ans[1] << "\n";
	}
	return 0;
}