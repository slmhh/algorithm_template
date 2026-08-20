#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
T exgcd(T a,T b,T &x,T &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	T d = exgcd(b,a % b,y,x);
	y = y - (a / b) * x;
	return d;
}

template<typename T>
T inv(T a,T p){
    T x,y;
    exgcd(a,p,x,y);
    return (x % p + p) % p;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        ll n;
        __int128 M = 1;
        cin >> n;
        vector<ll> a(n + 1),m(n + 1);
        for(int i = 1;i <= n;i++){
            cin >> m[i] >> a[i];
            M *= m[i];
        }
        __int128 sum = 0;
        for(int i = 1;i <= n;i++){
            __int128 tm = M / m[i];
            sum = (sum + ((__int128)a[i] * tm) % M * inv(tm,(__int128)m[i]) % M) % M;
        }
        cout << (ll)sum << "\n";
    }   
    return 0;
}