#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10,mod = 1e9 + 7;

struct xorBase{
    vector<ll> p;
    xorBase(){
        p.resize(65,0);
    }
    
    void insert(ll x){
        for(int i = 60;i >= 0;i--){
            if(x >> i){
                if(p[i]) x ^= p[i];
                else{
                    p[i] = x;
                    return;
                }
            }
        }
    }
};

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,t;
    cin >> n;
    xorBase b;
    for(int i = 1;i <= n;i++){
        cin >> t;
        b.insert(t);
    }
    ll ans = 0;
    for(int i = 60;i >= 0;i--){
        if((b.p[i] ^ ans) > ans)
            ans ^= b.p[i];
    }
    cout << ans << "\n";
    return 0;
}
