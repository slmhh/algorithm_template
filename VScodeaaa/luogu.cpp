#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e5 + 10;

struct tos{
	vector<ll> to;
};
ll n,m;
vector<tos> g;
void bfs(){
	queue<ll> d;
	ll st[n + 5] = {0}; 
	d.push(1);
	while(!d.empty()){
		ll t = d.front();
		d.pop();
		if(!st[t]){
			cout << t << " ";
			st[t]++;
		}
		else{
			continue;
		}
		for(int i = 0;i < g[t].to.size();i++){
			d.push(g[t].to[i]);
		}
	}
	cout << "\n";
}

map<ll,ll> st;
void dfs(ll idx){
	if(st[idx]) return;
	cout << idx << " ";
	st[idx]++;
	for(int i = 0;i < g[idx].to.size();i++){
		dfs(g[idx].to[i]);
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	g.resize(n + 5);
	for(int i = 0;i < m;i++){
		ll x,y;
		cin >> x >> y;
		g[x].to.push_back(y);
	}
	for(int i = 1;i <= n;i++){
		if(g[i].to.size() != 0) sort(all(g[i].to));
	}
	dfs(1);
	cout << "\n";
	bfs();
	return 0;
}