/*#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e5 + 10;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;
	unordered_map<ll,ll> s;
	cin >> n >> m;
	while(m--){
		ll op,i,j,k;
		cin >> op >> i >> j;
		if(op == 1){
			cin >> k;
			s[i * 100000 + j] = k;
		}
		else cout << s[i * 100000 + j] << "\n";
	}
	return 0;*/
	#include<iostream>
using namespace std;

int ans[13],x[13] = {0},y[13] = {0},rb[30] = {0},lb[30] = {0};
int n,cnt = 0;
void dfs(int a){
    if(a >= n){
        cnt++;
        if(cnt > 3) return ;
        for(int i = 0;i < n;i++)
            cout << ans[i] << " ";
        cout << "\n";
        return ;
    }
    for(int i = 0;i < n;i++){
        if(x[a] || y[i]  || rb[a - i + n]  || lb[a + i] ) continue;
        x[a] = y[i] = rb[a - i + n] = lb[a + i] = 1;
        ans[a] = i + 1;
        dfs(a + 1);
        x[a] = rb[a - i + n] = y[i] = lb[a + i]  = 0;
    }
}

int main(){
    cin >> n;
    dfs(0);
    cout << cnt << "\n";
    return 0;
}