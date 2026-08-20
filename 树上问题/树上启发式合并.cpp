#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e5 + 10,mod = 998244353;

//dsu on tree O(nlong n)
// son:重儿子,L[u]: 结点 u 的 DFS 序,R[u]: 结点 u 子树中结点的 DFS 序的最大值,Node[i]: DFS 序为 i 的结点
// ans: 存答案,cnt[i]: 颜色为 i 的结点个数,totColor: 目前出现过的颜色个数
ll n,idx,col[N],siz[N],node[N],l[N],r[N],son[N];
ll ans[N],cnt[N],colcnt;
vector<ll> edge[N];

void add(ll p){
    if(cnt[col[p]] == 0) colcnt++;
    cnt[col[p]]++;
}

void del(ll p){
    cnt[col[p]]--;
    if(cnt[col[p]] == 0) colcnt--;
}

void dfs(ll p,ll f){
    l[p] = ++idx;
    node[idx] = p;
    siz[p] = 1;
    for(auto& i : edge[p]){
        if(i == f) continue;
        dfs(i,p);
        siz[p] += siz[i];
        if(!son[p] || siz[son[p]] < siz[i]) son[p] = i;
    }
    r[p] = idx;
}

//只保留对重儿子的操作
void dfs1(ll p,ll f,bool keep){
    for(auto& i : edge[p]){
        if(i == f || i == son[p]) continue;
        dfs1(i,p,false);
    }
    if(son[p]){
        dfs1(son[p],p,true);
    }
    for(auto& i : edge[p]){
        if(i == f || i == son[p]) continue;
        // 子树结点的 DFS 序构成一段连续区间
        for(int j = l[i];j <= r[i];j++){
            add(node[j]);
        }
    }
    add(p);
    ans[p] = colcnt;
    if(!keep){
        for(int i = l[p];i <= r[p];i++){
            del(node[i]);
        }
    }
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m,q,u,v;
    cin >> n;
    for(int i = 2;i <= n;i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i = 1;i <= n;i++){
        cin >> col[i];
    }
    dfs(1,0);
    dfs1(1,0,false);
    cin >> q;
    for(int i = 1;i <= q;i++){
        cin >> u;
        cout << ans[u] << "\n";
    }
    return 0;
}