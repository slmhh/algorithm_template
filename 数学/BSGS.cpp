#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;

ll BSGS(ll a,ll b,ll p){
    ll A = sqrtl(p) + 1;
    unordered_map<ll,ll> mp;
    ll cur = 1;
    for(int i = 1;i <= A;i++){
        cur = (cur * a) % p;
        mp[(cur * b) % p] = i;
    }
    ll temp = cur;
    for(int i = 1;i <= A;i++){
        auto it = mp.find(temp);
        if(it != mp.end()) return i * A - it->second;
        temp = (temp * cur) % p;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll a,b,p;
    cin >> p >> a >> b;
    ll temp = BSGS(a,b,p);
    if(temp != -1) cout << temp << "\n";
    else cout << "no solution\n";
    return 0;
}