#include<bits/stdc++.h>
using namespace std;

//ÎÞ¸ºÈ¨±ß 
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e6 + 10;

struct edge{
	ll next; 
	ll to; 
	ll weight;  
};

ll head[N],dist[N],n,m,start = 1,res = 0,cnt = 0;
bool st[N];
vector<edge> e;

void add(int a,int b,int c){
	e.push_back({head[a],b,c}); 
	head[a] = e.size() - 1;
} 

void prim(){
	priority_queue <PII,vector<PII>,greater<PII> > heap;
	heap.push({0,start}); 
	
	memset(dist,0x3f3f3f3f,sizeof(dist)); 
	dist[start] = 0;
	 
	while(heap.size()){
		PII t = heap.top();
		heap.pop();
		
		ll ver = t.second,d = t.first;
		if(st[ver] == 1) continue;
		st[ver] = 1;
		res += d;
		cnt++;
		
		for(int i = head[ver];i != -1;i = e[i].next){
			ll j = e[i].to,k = e[i].weight;
			if(dist[j] > k){
				dist[j] = k;
				heap.push({dist[j],j});
			}
		} 
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	memset(head,-1,sizeof(head));
	while(m--){
		ll x,y,z;
		cin >> x >> y >> z;
		add(x,y,z);
		add(y,x,z);
	}		
	prim();
	if(cnt == n) cout << res << "\n";
	else cout << "orz\n";
	return 0;
}
 
