#include<bits/stdc++.h>
using i64 = long long;
static constexpr int N = 1e5 + 10;

struct BIT{
    std::vector<i64> tr;
    i64 n;
    BIT():tr(N){};
    BIT(i64 _n):tr(_n + 1),n(_n + 1){};
    void update(i64 p,i64 x){
        for(int i = p;i < n;i += i & -i)
            tr[i] += x;
    }
    
    i64 query(i64 p){
        i64 res = 0;
        for(int i = p;i >= 1;i -= i & -i)
            res += tr[i];
        return res;
    }
};

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	int T = 1;
    std::cin >> T;
    while(T--){
        i64 n;
        std::cin >> n;
        std::vector<i64> slm(n + 1);
        BIT a,b;
        for(int i = 1;i <= n;i++){
            std::cin >> slm[i];
            b.update(slm[i],1);
        }
        i64 ans = 0;
        for(int i = 1;i <= n;i++){
            b.update(slm[i],-1);
            i64 ls,lb,rs,rb,lm,rm;
            ls = a.query(slm[i]);
            lm = ls - a.query(slm[i] - 1);
            lb = i - 1 - ls;
            ls -= lm;
            rs = b.query(slm[i]);
            rm = rs - b.query(slm[i] - 1);
            rb = n - i - rs;
            rs -= rm;
            ans += ls * (rm + rb) + lm * (n - i) + lb * (rm + rs);
            a.update(slm[i],1);
//             cout << ans << "\n";
        }
        std::cout << ans << "\n";
    }
	return 0;
}
