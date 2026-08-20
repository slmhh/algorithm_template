#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e5 + 10,mod = 998244353;

ll ans;
struct ODT{
    set<array<ll,3>> tr;
    ODT(){};
    auto split(ll p){
        auto t = tr.lower_bound({p,0,0});
        if(t != tr.end() && (*t)[0] == p) return t;
        t--;
        auto [l,r,v] = *t;
        tr.erase(t);
        tr.insert({l,p - 1,v});
        return tr.insert({p,r,v}).first;
    }

    void assign(ll l,ll r,ll v){
        auto end = split(r + 1),it = split(l),begin = it;
        ll sum = 0,cnt1 = 0;
        for(;it != end;it++){
            auto [tl,tr,tv] = *it;
            sum += tr - tl + 1;
            cnt1 += tv * (tr - tl + 1);
        }
        tr.erase(begin,end);
        tr.insert({l,r,v});
        if(v == 1) ans += sum - cnt1; 
        else ans -= cnt1;
    }
};

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        ll n,q;
        cin >> n >> q;
        ans = n;
        ODT t;
        t.tr.insert({1,n,1});
        while(q--){
            ll l,r,k;
            cin >> l >> r >> k;
            if(k == 1) t.assign(l,r,0);
            else t.assign(l,r,1);
            cout << ans << "\n";
        }
    }
	return 0;
}
