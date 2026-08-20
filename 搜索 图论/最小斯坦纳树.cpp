#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 5e2 + 10,M = 5e4 + 10,mod = 1e6 + 7;

vector<PII> edge[N];
ll key[12],dp[N][M],n,m,k,vis[N];
priority_queue<PII,vector<PII>,greater<PII>> q;

void dijkstra(ll s){
	for(int i = 0;i <= n;i++)
		vis[i] = 0;	
	while(!q.empty()){
		PII t = q.top();
		q.pop();
		if(vis[t.second]) continue;
		vis[t.second] = 1;
		for(auto i : edge[t.second]){
			ll v = i.first,w = i.second;
			if(dp[v][s] > dp[t.second][s] + w){
				dp[v][s] = dp[t.second][s] + w;
				q.push({dp[v][s],v});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		ll u,v,w;
		cin >> u >> v >> w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= (1LL << k);j++){
			dp[i][j] = 1e15;
		}
	}
	for(int i = 1;i <= k;i++){
		cin >> key[i];
		dp[key[i]][1LL << (i - 1)] = 0; 
	}
	for(ll s = 1;s <= (1LL << k) - 1;s++){
		for(int i = 1;i <= n;i++){
			for(ll sub = s & (s - 1);sub > 0;sub = s & (sub - 1)){
				dp[i][s] = min(dp[i][s],dp[i][sub] + dp[i][sub ^ s]); 
			}
			if(dp[i][s] < 1e15) q.push({dp[i][s],i});
		}
		dijkstra(s);
	}
	cout << dp[key[1]][(1LL << k) - 1] << "\n";
	return 0;
}
 