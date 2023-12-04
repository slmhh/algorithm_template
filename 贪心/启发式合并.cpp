#include<bits/stdc++.h>
#define debug(x) cout << "#x" << x << endl;
#define all(x) (x).begin(),(x).end()
using namespace std;

//P3201 [HNOI2009]梦幻布丁、
//小区间放到大区间 

typedef long long ll;
const int N = 1e5 + 10;

ll ans,n,m; 
ll color[N],nowColor[N];
vector<ll> site[N];  //存每个颜色的位置 

void merge_(ll x,ll y){
	for(auto i : site[x]){
		if(color[i - 1] == y) ans--;  
		if(color[i + 1] == y) ans--;
	}
	for(auto i : site[x]){
		color[i] = y;  //染色 
		site[y].push_back(i); 
	}
	site[x].clear();
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> color[i];
		nowColor[color[i]] = color[i];
		site[color[i]].push_back(i);
		if(color[i] != color[i - 1]) ans++;
	}
	ll op,x,y;
	while(m--){
		cin >> op;
		if(op == 2) cout << ans << "\n";
		else{
			cin >> x >> y;
			if(x == y) continue;
			if(site[nowColor[x]].size() > site[nowColor[y]].size()) swap(nowColor[x],nowColor[y]);  //小区间放到大区间 
			merge_(nowColor[x],nowColor[y]);
		}
	}
    return 0;
}
