#include<bits/stdc++.h>
using i64 = long long;

int main(){
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    i64 n;
    std::cin >> n;
    std::vector<i64> a;
    while(n--){
        i64 opt,x;
        std::cin >> opt >> x;
        //插入O(log n)
        if(opt == 1)      a.insert(lower_bound(a.begin(),a.end(),x),x);
        //删除O(log n)
        else if(opt == 2) a.erase(lower_bound(a.begin(),a.end(),x));
        //查询排名O(log n)
        else if(opt == 3) std::cout << lower_bound(a.begin(),a.end(),x) - a.begin() + 1 << "\n";
        //查询排名对应数字O(1)
        else if(opt == 4) std::cout << a[x - 1] << "\n";
        //前驱O(log n) 
        else if(opt == 5) std::cout << *(lower_bound(a.begin(),a.end(),x) - 1) << "\n";
        //后继O(log n)
        else              std::cout << *upper_bound(a.begin(),a.end(),x) << "\n";
    }
    return 0;
}