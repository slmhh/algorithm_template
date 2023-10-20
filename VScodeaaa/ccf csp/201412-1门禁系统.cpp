#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,t;
    map<int,int> m;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> t;
        cout << m[t] + 1 << " ";
        m[t]++;
    }
    return 0;
}