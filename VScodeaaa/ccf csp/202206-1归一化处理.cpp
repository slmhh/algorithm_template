#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    double a[1100],avg = 0,d = 0;
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        avg += a[i];
    }
    avg /= n;
    for(int i = 0;i < n;i++){
        d += (a[i] - avg) * (a[i] - avg);
    }
    d /= n;
    for(int i = 0;i < n;i++){
        printf("%.10f\n",(a[i] - avg) / sqrt(d));
    }
    return 0;
}