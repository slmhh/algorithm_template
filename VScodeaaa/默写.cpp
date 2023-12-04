#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;

ll st[N][20],n,m;

ll query(ll l,ll r){
    ll k = log2(r - l + 1); 
    return st[l][k] & st[r - (1 << k) + 1][k]; 
}

void build_st(){
	for(int j = 1;j <= 20;j++)
        for(int i = 1;i + (1 << j) - 1 <= n;i++)
            st[i][j] = st[i][j - 1] & st[i + (1 << (j - 1))][j - 1];
}

bool check(ll l,ll r,ll k){
	if(query(l,r) >= k) return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	//T = 1;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> st[i][0];
		build_st();
		cin >> m;
		while(m--){
			ll t,k;
			cin >> t >> k;
			if(st[t][0] < k){
				cout << "-1 ";
				continue;
			}
			ll ans,r = n,l = t;
			while(l <= r){
				ll mid = (l + r) >> 1;
				if(check(t,mid,k)){
					l = mid + 1;
					ans = mid;
				}
				else r = mid - 1;
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
	return 0;
}