#include<bits/stdc++.h>

// https://www.luogu.com.cn/problem/P3805 【模板】Manacher
struct Manacher{
    std::vector<int> p;
    //奇偶归一化处理
    std::string change(std::string& str){
        std::string temp = "!#";
        for(int i = 0;i < str.size();i++){
            temp += str[i];
            temp += '#';
        }
        return temp;
    }

    void get_p(std::string& str){
        int maxright = 0,mid = 0;
        str = change(str);
        p.assign(str.size(),0);
        for(int i = 1;i < str.size();i++){
            //对称
            if(i < maxright){
                p[i] = std::min(p[2 * mid - i],maxright - i + 1);
            }
            else{
                p[i] = 1 + (str[i] != '#');
            }
            //扩展
            while(i - p[i] >= 0 && p[i] + i < str.size() && str[i - p[i]] == str[i + p[i]]){
                p[i]++;
            }
            //变更最右回文子串
            if(i + p[i] - 1 > maxright){
                mid = i;
                maxright = i + p[i] - 1;
            }
        }
    }
    // 返回最大回文串长度
    int get_max(std::string& str){
        get_p(str);
        int res = 0;
        for(int i = 1;i < p.size();i++){
            res = std::max(res,p[i] - 1);
        }
        return res;
    }
};

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    std::string str;
    std::cin >> str;
    Manacher manacher;
    std::cout << manacher.get_max(str) << "\n";
    return 0;
}