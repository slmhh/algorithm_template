#include<bits/stdc++.h>
using i64 = long long;

struct MCMF{
    static constexpr i64 INF = 1e18;
    int n,s,t;
    std::vector<int> head,cur,inq,vis;
    std::vector<i64> dist;

    MCMF(int _n,int _s,int _t):
    n(_n),s(_s),t(_t),
    head(_n + 1,-1),cur(_n + 1),dist(_n + 1),
    inq(_n + 1),vis(_n + 1){}

    struct edge{
        i64 to,ne,w,c;
    };
    std::vector<edge> e;

	void add(int u,int v,i64 w, i64 c){
        e.push_back({v,head[u],w,c});
		head[u] = e.size() - 1;	
	}

	void addEdge(int u, int v,i64 w,i64 c){
		add(u, v, w, c);
		add(v, u, 0, -c);
	}

	bool SPFA(){
		std::queue<int> q;
        cur = head;
        std::fill(dist.begin(),dist.end(),1e18);
        dist[s] = 0;
		q.push(s);
		while (!q.empty()){
			i64 p = q.front();
			q.pop();
			inq[p] = 0;
			for (int i = head[p];i != -1;i = e[i].ne){
				i64 v = e[i].to, w = e[i].w;
				if (w > 0 && dist[v] > dist[p] + e[i].c){
					dist[v] = dist[p] + e[i].c;
					if (!inq[v]){
						q.push(v);
						inq[v] = 1;
					}
				}
			}
		}
		return dist[t] < INF;
	}

	i64 dfs(int p,i64 flow = INF){
		if(p == t || flow == 0)
			return flow;
        vis[p] = 1;
		i64 rest = flow;
		for(int i = cur[p];i != -1 && rest;i = e[i].ne){
			i64 v = e[i].to,w = e[i].w;
			cur[p] = i;
			if(w > 0 && !vis[v] && dist[v] == dist[p] + e[i].c){
				i64 c = dfs(v,std::min(rest,w));
				rest -= c;
				e[i].w -= c;
				e[i ^ 1].w += c;
			}
		}
        vis[p] = 0;
		return flow - rest;
	}

	i64 maxflow,mincost;
	void work(){
		maxflow = mincost = 0;
		while (SPFA()){
			i64 flow = dfs(s);
			maxflow += flow;
			mincost += dist[t] * flow;
		}
	}
};

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	int n,m,s,t,u,v,w,c;
	std::cin >> n >> m >> s >> t;
	MCMF f(n,s,t);
	for(int i = 1;i <= m;i++){
		std::cin >> u >> v >> w >> c;
		f.addEdge(u,v,w,c);
	}
	f.work();
	std::cout << f.maxflow << " " << f.mincost << "\n";
	return 0;
}
 