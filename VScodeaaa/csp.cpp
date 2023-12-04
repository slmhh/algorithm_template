#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,k,sum = 0,ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n;i++){
        ll t;
        cin >> t;
        sum += t;
        if(sum >= k){
            sum = 0;
            ans++;
        }
    }
    if(sum > 0) ans++;
    cout << ans << "\n";
    return 0;
}