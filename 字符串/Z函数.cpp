#include<bits/stdc++.h>
using i64 = long long;

template<typename T>
std::vector<int> z_function(const T& str){
    int n = str.size();
    std::vector<int> z(n);
    int j = 0;
    for(int i = 1;i < n;i++){
        z[i] = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i,z[i - j]);
        while(i + z[i] < n && str[z[i]] == str[i + z[i]]){
            z[i]++;
        }
        if(j + z[j] < i + z[i]){
            j = i;
        }
    }
    z[0] = n;
    return z;
}


int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0;i < n;i++){
            std::cin >> a[i];
        }
        auto tmp = z_function(a);
        int ans = -1;
        for(int i = 1;i < n;i++){
            if(tmp[i] != n - i){
                ans = i;
            }
            std::cout << ans << " \n"[i == n - 1];
        }
    }
    return 0;
}

