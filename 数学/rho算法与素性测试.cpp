#include<bits/stdc++.h>
using namespace std;
using ll = long long;
std::mt19937_64 rng {std::chrono::steady_clock::now().time_since_epoch().count()};

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b,a % b);
}

ll qpow(ll a, ll n, ll p){
    ll ans = 1;
    while (n){
        if(n & 1) ans = (__int128)ans * a % p;
        a = (__int128)a * a % p;
        n >>= 1;
    }
    return ans;
}

bool Miller_Rabin(ll x){
    if (x < 3) return x == 2;
    if (x % 2 == 0) return false;
    constexpr ll A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	ll d = x - 1, r = 0;
    while (d % 2 == 0) d /= 2, ++r;
    for (auto a : A){
        ll v = qpow(a, d, x);
        if(v <= 1 || v == x - 1) continue;
        for(int i = 0; i < r; ++i){
            v = (__int128)v * v % x;
            if(v == x - 1 && i != r - 1){
                v = 1;
                break;
            }
            if(v == 1)  return false;
        }
        if(v != 1) return false;
    }
    return true;
}

ll Pollard_Rho(ll N){
    if (N == 4) return 2;
    if (Miller_Rabin(N))return N;
    while(true){
        ll c = rng() % (N - 1) + 1;
        auto f = [=](ll x) {return ((__int128)x * x + c) % N;};
        ll t = 0, r = 0, p = 1,q;
        do{
            for(int i = 0; i < 128; ++i){
                t = f(t),r = f(f(r));
                if (t == r || (q = (__int128)p * abs(t - r) % N) == 0)
                    break;
                p = q;
            }
            ll d = gcd(p, N);
            if (d > 1) return d;
        }while (t != r);
    }
	return N;
}

unordered_map<ll, ll> um;
ll max_prime_factor(ll x){
    if(um.count(x)) return um[x];
    ll fac = Pollard_Rho(x);
    if(fac == 1 || fac == x) um[x] = x;
    else um[x] = max(max_prime_factor(fac),max_prime_factor(x / fac));
    return um[x];
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll T = 1;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
 		ll ans = max_prime_factor(n);
		if(ans == n) cout << "Prime\n";
		else cout << ans << '\n';
  	}
	return 0;
}