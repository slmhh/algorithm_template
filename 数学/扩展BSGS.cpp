#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;

ll BSGS(ll a,ll b,ll p,ll k = 1){
    ll A = sqrtl(p) + 1;
    map<ll,ll> mp;
    ll cur = 1;
    for(int i = 1;i <= A;i++){
        cur = (cur * a) % p;
        mp[(cur * b) % p] = i;
    }
    ll temp = cur * k % p;
    for(int i = 1;i <= A;i++){
        auto it = mp.find(temp);
        if(it != mp.end()) return i * A - it->second;
        temp = (temp * cur) % p;
    }
    return -1e18;
}

ll exBSGS(ll a, ll b, ll m, ll k = 1){
    a %= m,b %= m;
    ll A = a, B = b, M = m;
    if (b == 1) return 0;
    ll cur = 1 % m;
    for (int i = 0;; i++){
        if (cur == B) return i;
        cur = cur * A % M;
        ll d = __gcd(a, m);
        if (b % d) return -1e18;
        if (d == 1) return BSGS(a, b, m, k * a % m) + i + 1;
        k = k * a / d % m, b /= d, m /= d;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(true){
        ll a,b,p;
        cin >> a >> p >> b;
        if(a == 0 && b == 0 && p == 0) break;
        ll temp = exBSGS(a,b,p);
        if(temp >= 0) cout << temp << "\n";
        else cout << "No Solution\n";
    }
    return 0;
}