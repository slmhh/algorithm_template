#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e2 + 10;

ll n,m,fri[N],vis[N];
vector<ll> e[N];

bool match(ll x,ll t){
    if(vis[x] == t) return false;
	vis[x] = t;
	for(auto i : e[x]){
		if(fri[i] == 0 || match(fri[i],t)){
			fri[i] = x;
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll k,a,b,cnt = 0;
	cin >> n >> m >> k;
	while(k--){
		cin >> a >> b;
		e[a].push_back(b);
	}
	for(int i = 1;i <= n;i++)
		if(match(i,i)) cnt++;
	cout << cnt << "\n";
	return 0;
}
 
