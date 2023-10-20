#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 10,B = 30;

 ll g[N][N] = {0};
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> g[i][j];
    for(int i = m - 1;i >= 0;i--){
        for(int j = 0;j < n;j++)
            cout << g[j][i] << " ";
        cout << "\n";
    }
    return 0;
}