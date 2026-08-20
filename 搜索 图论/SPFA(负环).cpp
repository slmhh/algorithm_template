#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int N = 2e3 + 10;

vector<PII> edge[N];
bool inque[N],flag;
ll dist[N],cnt[N],n,m,u,w,v;

void SPFA(ll p){
	queue<ll> q;
	q.push(p);
	dist[p] = 0;
	while(!q.empty()){
		auto temp = q.front();
		q.pop();
		inque[temp] = false;
		for(auto i : edge[temp]){
			if(i.second + dist[temp] < dist[i.first]){
				dist[i.first] = dist[temp] + i.second;
				if(!inque[i.first]){
					cnt[i.first]++;
					if(cnt[i.first] >= n){
						flag = true;
						return;
					}
					inque[i.first] = true;
					q.push(i.first);
				}
			}
		}
	}
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll T = 1;
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 1;i <= n;i++){
			edge[i].clear();
			inque[i] = false;
			cnt[i] = 0;
			dist[i] = 1e16;
		}
		for(int i = 1;i <= m;i++){
			cin >> u >> v >> w;
			edge[u].push_back({v,w});
			if(w >= 0) edge[v].push_back({u,w});
		}
		flag = false;
		SPFA(1);
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
 