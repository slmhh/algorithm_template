#include<bits/stdc++.h>
using i64 = long long;

template<typename T>
int get_min_str(const T& str){  //返回循环同构字符串的最小字典序首位下标
    int i = 0,j = 1,k = 0;
    int n = str.size();
    while(i < n && j < n && k < n){
        int tmp = str[(i + k) % n] - str[(j + k) % n];
        if(tmp == 0){
            k++;
        }
        else{
            if(tmp > 0) i += k + 1;
            else j += k + 1;
            if(i == j) j++;
            k = 0;
        }
    }
    return std::min(i,j);
}

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int n;
    std::string str;
    std::cin >> n >> str;
    int idx = get_min_str(str);
    for(int i = 0;i < n;i++){
        std::cout << str[(i + idx) % n];
    }
    return 0;
}

