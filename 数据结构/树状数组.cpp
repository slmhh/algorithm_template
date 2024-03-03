#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int N = 5e5 + 10;

ll a[N],c[N],n,m;

ll lowbit(ll x){
	return x & -x;
}

void init(){
	for(int i = 1;i <= n;i++){
		c[i] += a[i];
		ll x = i + lowbit(i);
		if(x <= n) c[x] += c[i];
	}
}

void add(ll x,ll k){
	for(int i = x;i <= n;i += lowbit(i))
	    c[i] += k;
}

ll getsum(ll x){
	ll res = 0;
	for(int i = x;i > 0;i -= lowbit(i))
	    res += c[i];
	return res;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	init();
	ll op,x,y;
	while(m--){
		cin >> op >> x >> y;
		if(op == 1) add(x,y);
		else cout << getsum(y) - getsum(x - 1) << "\n";
	}
	return 0;
}
