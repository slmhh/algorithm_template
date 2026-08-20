#include<bits/stdc++.h>
using i64 = long long;

struct SCC{
    // st：是否在栈中  scc：每个点所属的强连通分量编号  cscc：强连通分量的数量
    std::vector<i64> dfn,low,stk,scc;
    std::vector<bool> st;
    std::vector<std::vector<i64>> e;
    i64 cscc,N,cnt = 0;
    SCC(int n): dfn(n + 1),low(n + 1),st(n + 1),
				scc(n + 1),e(n + 1),cscc(0),N(n){}

    void add(i64 u,i64 v){
        e[u].push_back(v);
    }

    void tarjan(i64 p){
        low[p] = dfn[p] = ++cnt;
        st[p] = true;
        stk.push_back(p);
        for(auto& q : e[p]){
            if(!dfn[q]){
                tarjan(q);
                low[p] = std::min(low[q],low[p]);
            }
            else if(st[q]){
                low[p] = std::min(low[p],dfn[q]);
            }
        }
        if(low[p] == dfn[p]){
            int top;
            cscc++;
            do{
                top = stk.back();
                stk.pop_back();
                st[top] = false;
                scc[top] = cscc;
            }while(top != p);
        }
    }

    void work(){
        for(int i = 1;i <= N;i++)
            if(!dfn[i])
                tarjan(i);
    }
};
//scc编号的顺序符合拓扑序（编号越大的点拓扑序越靠前）

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    i64 n,m,ans = 0;
    std::cin >> n >> m;
    SCC a(n);
    std::vector<i64> w(n + 1),nw;
    for(int i = 1;i <= n;i++) std::cin >> w[i];
    for(int i = 1;i <= m;i++){
        i64 u,v;
        std::cin >> u >> v;
        a.add(u,v);
    }
    a.work();
    nw.resize(a.cscc + 1,0);
    std::vector<std::vector<i64>> edge(a.cscc + 1);
    std::vector<i64> dp(a.cscc + 1,0);
    for(int i = 1;i <= n;i++){
        nw[a.scc[i]] += w[i];
        dp[a.scc[i]] += w[i];
        ans = std::max(ans,dp[a.scc[i]]);
        for(auto& j : a.e[i]){
            if(a.scc[i] != a.scc[j]){
                edge[a.scc[i]].push_back(a.scc[j]);
            }
        }
    }
    for(int i = a.cscc;i >= 1;i--){
        for(auto& j : edge[i]){
            dp[j] = std::max(dp[j],dp[i] + nw[j]);
            ans = std::max(ans,dp[j]);
        }
    }
    std::cout << ans << "\n";
	return 0;
}