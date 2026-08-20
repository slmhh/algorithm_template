#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10,b = 61,mod1 = 998244353;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        ll l = 2,r = 1000,ans = 0;
        while(l <= r){
            ll m1 = (l + r) / 3,m2 = (l + r) / 3 * 2,t;
            cout << "? " << m1 << " " << m2 << endl;
            cin >> t;
            if(t == m1 * m2){
                l = m2 + 1;
            }
            else if(t == m1 * (m2 + 1)){
                l = m1 + 1,r = m2 - 1;
            }
            else r = m1 - 1;
        }
        cout << "! " << ans << endl;
    }
 	return 0;
}
 