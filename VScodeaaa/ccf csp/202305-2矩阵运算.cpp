#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void read(vector<vector<ll>> &t){
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> t[i][j];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> q(n,vector<ll>(m)),k(n,vector<ll>(m)),v(n,vector<ll>(m)),temp(m,vector<ll>(m));
    vector<ll> w(n);
    read(q);
    read(k);
    read(v);

    for(int i = 0;i < n;i++) cin >> w[i];

    //temp = matrix_x(k,v);
    for(int i = 0;i < m;i++)
        for(int j = 0;j < m;j++)
            for(int l = 0;l < n;l++)
                temp[i][j] += k[l][i] * v[l][j];

    //ans = matrix_x(q,temp);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            ll ans = 0;
            for(int l = 0;l < m;l++)
                ans += q[i][l] * temp[l][j];
            cout << ans * w[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}