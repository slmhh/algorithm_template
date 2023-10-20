#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n;
    vector<ll> m(n);
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> m[i];
    ll cnt = 0;
    for(int i = 0;i < n;i++){
        cnt++;
        while(i + 1 < n && m[i] == m[i + 1]) i++;
    }
    cout << cnt << "\n";
    return 0;
}

//STL中unique实现
/*int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,t;
    vector<ll> m;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> t;
        m.push_back(t);
    }
    ll cnt = unique(m.begin(),m.end()) - m.begin();
    cout << cnt << "\n";
    return 0;
}*/