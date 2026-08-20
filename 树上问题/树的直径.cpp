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

	std::vector<int> dp(n + 1);
	int ans = 0;
	auto dfs = [&](auto&&self,int p,int f) -> void{
		for(auto v : edge[p]){
			if(v == f) continue;
			self(self,v,p);
			ans = std::max(ans,dp[p] + dp[v] + 1);
			dp[p] = std::max(dp[p],dp[v] + 1);
		}
	};
	dfs(dfs,1,0);
	std::cout << ans << "\n";
	return 0;
}