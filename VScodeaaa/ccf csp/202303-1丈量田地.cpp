#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,a,b,ans = 0;
    cin >> n >> a >> b;
    ll x1,x2,y1,y2;
    while(n--){
        cin >> x1 >> y1 >> x2 >> y2;
        ans += max((min(x2,a) - max(x1,0LL)),0LL) * max((min(y2,b) - max(y1,0LL)),0LL);
    }
    cout << ans << "\n";
    return 0;
}