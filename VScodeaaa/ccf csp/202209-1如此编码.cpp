#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll a[30],b,n,m,sum = 0;
    cin >> n >> m;
    a[0] = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        a[i] *= a[i - 1];
    }
    for(int i = 0;i < n;i++){
        b = (m % a[i + 1] - sum) / a[i];
        sum += b * a[i];
        cout << b << " ";
    }
    return 0;
}