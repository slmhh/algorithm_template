#include<bits/stdc++.h>
using i64 = long long;
typedef std::pair<i64,i64> PII;
const int N = 1e6 + 10;

i64 pow1[N],pow2[N];
struct string_hash{
    const int Base = 499,M1 = 998244853,M2 = 989244353;  
    std::string str;
    std::vector<i64> hash1,hash2;
    void extend(char c,int idx){
        pow1[idx] = (pow1[idx - 1] * Base) % M1;
        hash1[idx] = (hash1[idx - 1] * Base + c) % M1;
        pow2[idx] = (pow2[idx - 1] * Base) % M2;
        hash2[idx] = (hash2[idx - 1] * Base + c) % M2;
    }

    void init(int n){
        hash1.resize(n + 1,0);
        hash2.resize(n + 1,0);
		for(int i = 0;i <= n + 2;i++)
			pow1[i] = pow2[i] = 1;
    }

    void init(std::string str){
        i64 n = str.size();
        init(n);
        this->str = str;
        for(int i = 0;i < n;i++){
            extend(str[i],i + 1);
        }
    }
    string_hash(){}
    string_hash(std::string str){init(str);}

    PII getHash(i64 l,i64 r){ // 1_idx
        i64 t1 = (hash1[r] - 1LL * hash1[l - 1] * pow1[r - l + 1]) % M1;
        t1 = (t1 + M1) % M1;
        i64 t2 = (hash2[r] - 1LL * hash2[l - 1] * pow2[r - l + 1]) % M2;
        t2 = (t2 + M2) % M2;
        return {t1,t2};
    }

    bool same(i64 l1,i64 r1,i64 l2,i64 r2){
        PII ta = getHash(l1,r1);
        PII tb = getHash(l2,r2);
        return ta.first == tb.first && ta.second == tb.second;
    }
};


int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    std::string str;
    std::cin >> str;
    string_hash h(str);
    int j = 2,n = str.size(),ans = 0;
    for(int i = 1;i <= n;i++){
        if(j + i - 1 >= n) break;
        if(!h.same(1,i,n - i + 1,n)) continue;
        while(j + i - 1 < n && !h.same(1,i,j,j + i - 1)){
            j++;
        }
        if(j + i - 1 < n && h.same(1,i,j,j + i - 1)){
            ans = i;
        }
    }
    if(ans == 0){
        std::cout << "Just a legend\n";
    }
    else{
        for(int i = 0;i < ans;i++){
            std::cout << str[i];
        }
    }
    return 0;
}
