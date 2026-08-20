#include<bits/stdc++.h>
using i64 = long long;

struct dinic{
	int n,s,t;
    std::vector<int> head,cur,level;
	struct edge{
		i64 to,ne,w;
	};
	std::vector<edge> e;

	dinic(int _n,int _s,int _t):
    n(_n),s(_s),t(_t),
    head(_n + 1,-1),cur(_n + 1,0),level(_n + 1,-1){}

	void addEdge(int u,int v,i64 w){
		e.push_back({v,head[u],w});
		head[u] = e.size() - 1;	
		e.push_back({u,head[v],0});
		head[v] = e.size() - 1;	
	}

	bool bfs(){
		std::queue<int> q;
		q.push(s);
        std::fill(level.begin(), level.end(), -1);
		level[s] = 0;
		while(!q.empty()){
			int p = q.front();
			q.pop();
			for(int i = head[p];i != -1;i = e[i].ne){
				i64 v = e[i].to,w = e[i].w;
				if(w > 0 && level[v] == -1){
					level[v] = level[p] + 1;
					q.push(v);
					if(v == t) return true;
				}
			}
		}
		return level[t] != -1;
	}

	i64 dfs(i64 p,i64 flow = 1e15){
		if(p == t || flow == 0)
			return flow;
		i64 rest = flow;
		for(int i = cur[p];i != -1 && rest;i = e[i].ne){
			i64 v = e[i].to,w = e[i].w;
			cur[p] = i;
			if(w > 0 && level[v] == level[p] + 1){
				i64 c = dfs(v,std::min(rest,w));
				rest -= c;
				e[i].w -= c;
				e[i ^ 1].w += c;
				if(rest == 0) return flow;
			}
		}
		return flow - rest;
	}

	i64 work(){
		i64 res = 0;
		while(bfs()){
            cur = head;
			res += dfs(s);
        }
		return res;
	}
};

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	int n,m,s,t,u,v,w;
	std::cin >> n >> m >> s >> t;
	dinic f(n,s,t);
	for(int i = 1;i <= m;i++){
		std::cin >> u >> v >> w;
		f.addEdge(u,v,w);
	}
	std::cout << f.work() << "\n";
	return 0;
}