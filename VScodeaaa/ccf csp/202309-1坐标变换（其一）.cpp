#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m,x = 0,y = 0,x1,y1;
    cin >> n >> m;
    while(n--){
        cin >> x1 >> y1;
        x += x1,y += y1;
    }
    while(m--){
        cin >> x1 >> y1;
        cout << x1 + x << " " << y1 + y << "\n";
    }
    return 0;
}