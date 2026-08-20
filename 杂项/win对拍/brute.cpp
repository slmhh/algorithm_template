#include<bits/stdc++.h>
using i64 = long long;

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    std::cin >> T;
    while(T--){
        i64 l,r;
        std::cin >> l >> r;
        i64 ans = 0;
        for(i64 i = l;i <= r;i--){
            i64 ti = i,x = 0;
            while(ti){
                x = x * 10 + ti % 10;
                ti /= 10;
            }
            ans = std::max(ans,x);
        }
        std::cout << ans << "\n";
    }
    return 0;
}
