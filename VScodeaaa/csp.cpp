#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

ll dp[20] = { 1,1,2,6,24,120,720,5040,40320,362880,0};
ll fac(ll n){
     if(dp[n] != 0) return dp[n];
     dp[n] = fac(n - 1) * n;
     return dp[n];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     fac(18);
     for(int i = 0;i < 20;i++){
          cout << dp[i] << "\n";
     }
    return 0;
}