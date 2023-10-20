#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,ans = 0;
    cin >> n;
    while(n > 0){
        ans += n % 10;
        n /= 10;
    }
    cout << ans << "\n";
    return 0;
}