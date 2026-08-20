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
            ll mid = (l + r) >> 1LL,t;
            cout << "? " << mid << " " << mid << endl;
            cin >> t;
            if(t > mid * mid){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << "! " << ans << endl;
    }
 	return 0;
}
 