#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e6 + 10;

ll n,m;
vector<ll> dist,st;
vector<PII> edge[N];
void dijkstra(ll start){
	priority_queue <PII,vector<PII>,greater<PII> > heap;
	heap.push({0,start}); 
	dist.resize(n + 1,1e10);
    st.resize(n + 1,0);
	dist[start] = 0; 
	 
	while(heap.size()){
		PII t = heap.top();
		heap.pop();
		
		int ver = t.second,d = t.first;
		if(st[ver] == 1) continue;
		st[ver] = 1;
		
		for(auto& [v,w] : edge[ver]){
			if(dist[v] > d + w){
				dist[v] = d + w;
				heap.push({dist[v],v});
			}
		} 
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll s;
	cin >> n >> m >> s;
	while(m--){
		ll x,y,z;
		cin >> x >> y >> z;
        edge[x].push_back({y,z});
	}		
	dijkstra(s);	
	for(int i = 1;i <= n;i++){
		cout << dist[i] << " ";
	}
	return 0;
}
 
