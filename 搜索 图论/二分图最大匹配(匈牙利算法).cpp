#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e2 + 10;

ll n,m,fri[N],vis[N];
vector<ll> e[N];

bool match(ll x,ll t){
    if(vis[x] == t) return false; //已经访问过 
	vis[x] = t; //记录状态为访问过
	for(auto i : e[x]){
		if(fri[i] == 0 || match(fri[i],t)){ //如果暂无匹配，或者原来匹配的左侧元素可以找到新的匹配
			fri[i] = x; //当前左侧元素成为当前右侧元素的新匹配
			return true; //返回匹配成功
		}
	}
	return false; //循环结束，仍未找到匹配，返回匹配失败
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