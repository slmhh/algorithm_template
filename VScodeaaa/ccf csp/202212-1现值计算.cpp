#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n;
    double i,pay = 0,mon = 0;
    scanf("%lld %lf",&n,&i);
    for(int j = 0;j <= n;j++){
        double t;
        scanf("%lf",&t);
        if(t < 0) pay += (-t * pow(1 + i,-j));
        else mon +=  (t * pow(1 + i,-j));
    }
    printf("%.3f",mon - pay);
    return 0;
}