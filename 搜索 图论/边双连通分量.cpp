#include<bits/stdc++.h>
using i64 = long long;

struct EBCC{
    // st：是否在栈中  ebcc：每个点所属的边双连通分量编号  cebcc：边双连通分量的数量
    std::vector<i64> dfn,low,stk,ebcc;
    std::vector<bool> st;
    std::vector<std::vector<std::array<i64,2>>> e;
    i64 cebcc,N,cnt,edge_cnt;
    
    EBCC(int n): dfn(n + 1),low(n + 1),st(n + 1),
                 ebcc(n + 1),e(n + 1),cebcc(0),N(n),
				 cnt(0),edge_cnt(1){}

    void add(i64 u,i64 v){
        e[u].push_back({v,edge_cnt << 1});
        e[v].push_back({u,edge_cnt << 1 | 1});
		edge_cnt++;
    }
	
    void tarjan(int p, int las){
		low[p] = dfn[p] = ++cnt;
		st[p] = true;
        stk.push_back(p);
		
		for(auto [q,idx]: e[p]){
			if(idx == (las ^ 1)) continue;
			if(!dfn[q]){
				tarjan(q, idx);
				low[p] = std::min(low[p], low[q]);
			}else low[p] = std::min(low[p], dfn[q]);
		}
		if(low[p] == dfn[p]){
            int top;
            cebcc++;
            do{
                top = stk.back();
                stk.pop_back();
                st[top] = false;
                ebcc[top] = cebcc;
            }while(top != p);
        }
	}

    void work(){
        for(int i = 1;i <= N;i++)
            if(!dfn[i])
                tarjan(i,0);
    }
    
    // 获取缩点后的树（边双连通分量缩点后的树）
    std::vector<std::vector<i64>> get_tree(){
        std::vector<std::vector<i64>> tree(cebcc + 1);
        
        for(int u = 1; u <= N; u++){
            for(auto& [v,_] : e[u]){
                if(ebcc[u] != ebcc[v]){
                    tree[ebcc[u]].push_back(ebcc[v]);
                }
            }
        }
        
        for(int i = 1; i <= cebcc; i++){
            std::sort(tree[i].begin(), tree[i].end());
            tree[i].erase(std::unique(tree[i].begin(), tree[i].end()), tree[i].end());
        }
        return tree;
    }
};

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    i64 n,m,u,v;
	std::cin >> n >> m;
	EBCC t(n);
	for(int i = 1;i <= m;i++){
		std::cin >> u >> v;
		t.add(u,v);
	}
	t.work();
	std::cout << t.cebcc << "\n";
	std::vector<std::vector<int>> ans(t.cebcc + 1);
	for(int i = 1;i <= n;i++) ans[t.ebcc[i]].push_back(i);
	for(int i = 1;i <= t.cebcc;i++){
		std::cout << ans[i].size() << " ";
		for(auto v : ans[i]) std::cout << v << " ";
		std::cout << "\n";
	}
	return 0;
}