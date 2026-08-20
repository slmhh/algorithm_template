#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
int mod = 1e9 + 7;
const int N = 2;
using Martix = array<array<int,N>,N>;
Martix mul(Martix& a,Martix& b){
    Martix res{};
    for(int k = 0;k < N;k++){
        for(int i = 0;i < N;i++){
            if(a[i][k] == 0) continue;
            for(int j = 0;j < N;j++){
                res[i][j] = (res[i][j] + ((long long)a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return res;
}

Martix qpow(Martix& a,int b){
    Martix temp{};
    for(int i = 0;i < N;i++) temp[i][i] = 1;
    while(b){
        if(b & 1) temp = mul(temp,a);
        a = mul(a,a);
        b >>= 1;
    }
    return temp;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        i64 p,q,a,b,n,m;
        cin >> p >> q >> a >> b >> n >> m;
        mod = m;
        if(n == 1) cout << a % mod << "\n";
        else if(n == 2) cout << b % mod << "\n";
        else{
            Martix temp;
            temp[0][0] = p,temp[1][0] = 1,temp[0][1] = q;
            temp = qpow(temp,n - 2);
            cout << (b * temp[0][0] % mod + a * temp[0][1] % mod) % mod << "\n";
        }
    }   
    return 0;
}