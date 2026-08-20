#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e4 + 10,mod = 1e9 + 7;

vector<ll> edge[N],cut;//cut 存储所有割点
ll dfn[N],low[N],cnt = 0;
void tarjan(ll p,bool root = true){
    ll tot = 0;
    cnt++;
    dfn[p] = low[p] = cnt;
    for(auto& i : edge[p]){
        if(!dfn[i]){
            tarjan(i,false);
            low[p] = min(low[p],low[i]);
            tot += (low[i] >= dfn[p]);
        }
        else low[p] = min(low[p],dfn[i]);
    }
    if(tot > root)
        cut.push_back(p);
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        ll u,v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i = 1;i <= n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    cout << cut.size() << "\n";
    sort(cut.begin(),cut.end());
    for(int i = 0;i < cut.size();i++){
        cout << cut[i] << " ";
    }
    return 0;
}
