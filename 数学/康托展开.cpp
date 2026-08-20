#include<bits/stdc++.h>
using i64 = long long;
static constexpr int N = 1e5 + 10;

struct BIT{
    std::vector<i64> tr;
    i64 n;
    BIT():tr(N){};
    BIT(i64 _n):tr(_n + 1),n(_n + 1){};
    void update(int p,i64 x){
        for(int i = p;i < n;i += i & -i)
            tr[i] += x;
    }
    
    i64 query(i64 p){
        i64 res = 0;
        for(int i = p;i >= 1;i -= i & -i)
            res += tr[i];
        return res;
    }

    i64 find_kth(i64 p){
        i64 pos = 0,sum = 0;
        for(int i = 1 << 20;i >= 1;i >>= 1){
            if(pos + i < n && tr[pos + i] + sum < p){
                sum += tr[pos + i];
                pos += i;
            }
        }
        return pos + 1;
    }
};

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	int n,m;
    std::cin >> n >> m;
    
    std::vector<i64> fac(22),a(n + 1);
    fac[0] = fac[1] = 1;
    for(int i = 2;i <= 20;i++) fac[i] = fac[i - 1] * i;

    bool tag = false;
    BIT t(n);

    while(m--){
        std::string str;
        std::cin >> str;
        if(str[0] == 'P'){
            if(!tag){
                for(int i = 1;i <= n;i++)
                    t.update(i,1);
            }
            i64 tp;
            std::cin >> tp;
            tp--;
            for(int i = 1;i <= n;i++){
                i64 temp = tp / fac[n - i];
                a[i] = t.find_kth(temp + 1);
                tp %= fac[n - i];
                t.update(a[i],-1);
            }
            for(int i = 1;i <= n;i++) std::cout << a[i] << " \n"[i == n];
            tag = false;
        }
        else{
            if(tag){
                for(int i = 1;i <= n;i++)
                    t.update(i,-1);
            }
            for(int i = 1;i <= n;i++) std::cin >> a[i];
            i64 ans = 0;
            for(int i = 1;i <= n;i++){
                t.update(a[i],1); 
                ans += (a[i] - t.query(a[i])) * fac[n - i];
            }
            std::cout << ans + 1 << "\n";
            tag = true;
        }
    }
	return 0;
}
