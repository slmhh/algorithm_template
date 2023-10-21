#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,t,s,ans = 0;
    cin >> n;
    cin >> t;
    for(int i = 1;i < n;i++){
        cin >> s;
        ans = max(ans,abs(s - t));
        t = s;
    }
    cout << ans << "\n";
    return 0;
}