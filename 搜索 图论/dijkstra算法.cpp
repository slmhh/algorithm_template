#include<bits/stdc++.h>
using i64 = long long;

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0); 
	int n,m,s;
	std::cin >> n >> m >> s;
	std::vector<std::vector<std::array<i64,2>>> edge(n + 1);
	for(int i = 1;i <= m;i++){
		i64 u,v,w;
		std::cin >> u >> v >> w;
		edge[u].push_back({v,w});
	}
	std::vector<i64> dist(n + 1),vis(n + 1);
	auto dijkstra = [&](int st) -> void{
		std::fill(dist.begin() + 1,dist.end(),1e10);
		std::fill(vis.begin() + 1,vis.end(),0);
		std::priority_queue<std::array<i64,2>,std::vector<std::array<i64,2>>,std::greater<std::array<i64,2>>> pq;
		dist[st] = 0;
		pq.push({0,st});
		while(!pq.empty()){
			auto [d,u] = pq.top();
			pq.pop();
			if(vis[u]) continue;
			vis[u] = 1;
			for(auto [v,w] : edge[u]){
				if(dist[v] > d + w){
					dist[v] = d + w;
					pq.push({d + w,v});
				}
			}
		}
	};
	dijkstra(s);

	for(int i = 1;i <= n;i++) std::cout << dist[i] << " ";
	return 0;
}