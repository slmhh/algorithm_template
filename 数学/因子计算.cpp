#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

vector<ll> va,vb;
set<ll> ans;
void all_gcd(ll x,vector<ll>& vx){
    for(int i = 1;i * i <= x;i++){
        if(x % i == 0){
            vx.push_back(i);
            vx.push_back(x / i);
        }
    }
}

int main(){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    all_gcd(a,va);
    all_gcd(b,vb);
    
    for(ll i : va){
        for(ll j : vb){
            ans.insert(i * j);
        }
    }
    
    cout << ans.size() << "\n";
    
    for(ll i : ans){
        printf("%lld ",i);
    }
    return 0;
}
    
