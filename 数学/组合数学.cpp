#include<bits/stdc++.h>
using i64 = long long;
static constexpr int N = 2e5 + 10,mod = 1e9 + 7;

i64 qpow(i64 a,i64 b){
    if(b == 0) return 1;
    i64 temp = qpow(a,b / 2);
    temp = (temp * temp) % mod;
    if(b & 1) temp = (temp * a) % mod;
    return temp;
}

i64 inv(i64 a){
    return qpow(a,mod - 2);
}

i64 fac[N],invfac[N];
i64 calc(i64 m,i64 n){
    return (fac[n] * ((invfac[m] * invfac[n - m]) % mod)) % mod;
}

void init(){
    fac[0] = fac[1] = 1;
    invfac[0] = invfac[1] = 1;
	for(int i = 2;i < N;i++){
		fac[i] = i;
		invfac[i] = (mod - mod / i) * invfac[mod % i] % mod;
	}
    for(int i = 2;i < N;i++){
		fac[i] = fac[i] * fac[i - 1] % mod;
		invfac[i] = invfac[i] * invfac[i - 1] % mod;
    }
}

int main(){ 
	std::ios::sync_with_stdio(0) ,std::cin.tie(0),std::cout.tie(0);
    int T; 
    std::cin >> T; 
    init(); 
    while(T--){ 
        i64 n,k,ans = 0,cnt1 = 0 ,cnt = 0;
        std::cin >> n >> k; 
        for(int i = 1;i <= n;i++){
            i64 t;
            std::cin >> t;
            if(t == 1) cnt1++;
        }
        cnt = n - cnt1;
        for(int i = k / 2 + 1;i <= cnt1 && i <= k;i++){
            if(i + cnt >= k) ans = (ans + calc(i,cnt1) * calc(k - i,cnt) % mod) % mod;
        }
        std::cout << ans << "\n";
    }
 	return 0;
}
 