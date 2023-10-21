#include<bits/stdc++.h>
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
	return 0;
}