#include<bits/stdc++.h>

// https://www.luogu.com.cn/problem/P8306 【模板】字典树 / Trie
template<int N = 26>
struct Trie{
    std::vector<std::array<int,N>> son;
    std::vector<int> cnt;

    Trie(){
        son.push_back(std::array<int,N>{});
        cnt.push_back(0);
    }

    void insert(std::string& str){  //插入 
        int p = 0,n = str.size();
        for(int i = 0;i < n;i++){
            int ch = str[i] - '0';
            if(!son[p][ch]){ //如果此处字母不存在就创建一个
                son[p][ch] = son.size();  
                son.push_back(std::array<int,N>{});
                cnt.push_back(0);
            }
            p = son[p][ch];  //指向下一个位置 
            cnt[p]++;
        }
        // cnt[p]++;  //该处单词数+1 
    }

    int find(std::string& str){  //找 
        int p = 0,n = str.size();
        for(int i = 0;i < n;i++){
            int ch = str[i] - '0';
            if(!son[p][ch]){
                return 0;
            }
            p = son[p][ch];
        }
        return cnt[p];
    }
};

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    std::cin >> T;
    while(T--){
        int n,q;
        std::cin >> n >> q;
        Trie<80> trie;
        std::string str;
        for(int i = 1;i <= n;i++){
            std::cin >> str;
            trie.insert(str);
        }
        for(int i = 1;i <= q;i++){
            std::cin >> str;
            int tmp = trie.find(str);
            std::cout << tmp << "\n";
        }
    }
	return 0;
}