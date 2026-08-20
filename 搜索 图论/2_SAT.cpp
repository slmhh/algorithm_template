#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SCC{
    // st：是否在栈中  scc：每个点所属的强连通分量编号  cscc：强连通分量的数量
    vector<ll> dfn,low,stk,scc;
    vector<bool> st;
    vector<vector<ll>> e;
    ll cscc,N,cnt = 0;
    SCC(int n){
        dfn.resize(n + 1,0);
        low.resize(n + 1,0);
        st.resize(n + 1,false);
        scc.resize(n + 1);
        e.resize(n + 1);
        cscc = 0;
        N = n;
    }

    void add(ll u,ll v){
        e[u].push_back(v);
    }

    void tarjan(ll p){
        low[p] = dfn[p] = ++cnt;
        st[p] = true;
        stk.push_back(p);
        for(auto& q : e[p]){
            if(!dfn[q]){
                tarjan(q);
                low[p] = min(low[q],low[p]);
            }
            else if(st[q]){
                low[p] = min(low[p],dfn[q]);
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
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m;
    cin >> n >> m;
    SCC sc(2 * n + 1);
    for(int i = 1;i <= m;i++){
        ll a,ta,b,tb;
        cin >> a >> ta >> b >> tb;
        sc.add((2 * a + ta) ^ 1,2 * b + tb);
        sc.add((2 * b + tb) ^ 1,2 * a + ta);
    }
    sc.work();
    bool flag = true;
    vector<ll> ans(n + 1);
    for(int i = 1;i <= n;i++){
        if(sc.scc[2 * i] == sc.scc[2 * i + 1]){
            flag = false;
            break;
        }
        else if(sc.scc[i * 2] > sc.scc[i * 2 + 1])
            ans[i] = 1;
        else ans[i] = 0;
    }
    if(flag){
        cout << "POSSIBLE\n";
        for(int i = 1;i <= n;i++){
            cout << ans[i] << " ";
        }
    }
    else cout << "IMPOSSIBLE\n";
	return 0;
}