#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,k,cnt = 0;
    cin >> n >> k;
    map<int,int> s;
    for(int i = 0;i < k;i++){
        ll x,y;
        cin >> x >> y;
        if(y != 0 && !s[y]) cnt++;
        s[x]++;
    }
    cout << cnt << "\n";
    return 0;
}