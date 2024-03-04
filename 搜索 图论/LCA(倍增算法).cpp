#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10,mod = 1e6 + 7;

struct edge{
	ll next,to;
};

vector<edge> e;
ll head[N],Log2[N], fa[N][20], dep[N]; // fa的第二维大小不应小于log2(N)
bool vis[N];

void add(ll a,ll b){
	e.push_back({head[a],b});
	head[a] = e.size() - 1;
}

//O(nlog n)预处理
void dfs(ll cur,ll fath = 0){
    if (vis[cur])
        return;
    vis[cur] = true;
    dep[cur] = dep[fath] + 1;
    fa[cur][0] = fath;
    for (int i = 1; i <= Log2[dep[cur]]; ++i)
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    for (int eg = head[cur]; eg != -1; eg = e[eg].next)
        dfs(e[eg].to, cur);
}

//O(log n)查询
ll lca(ll a,ll b){
    if (dep[a] > dep[b])
        swap(a, b);
    while (dep[a] != dep[b])
        b = fa[b][Log2[dep[b] - dep[a]]];
    if (a == b)
        return a;
    for (int k = Log2[dep[a]]; k >= 0; k--)
        if (fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];
    return fa[a][0];
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m,s,a,b;
	cin >> n >> m >> s;
	for(int i = 0;i <= n;i++) head[i] = -1;
	for(int i = 0;i < n - 1;i++){
		cin >> a >> b;
		add(a,b);
		add(b,a);
	}
	for (int i = 2; i <= n; ++i)
        Log2[i] = Log2[i / 2] + 1;  //预处理出log2(x)
	dfs(s);
	while(m--){
		cin >> a >> b;
		cout << lca(a,b) << "\n";
	}
	return 0;
}
 
