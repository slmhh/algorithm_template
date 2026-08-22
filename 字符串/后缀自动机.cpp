#include<bits/stdc++.h>
using i64 = long long;

// https://www.luogu.com.cn/problem/P3804 【模板】后缀自动机（SAM）
template<int N = 26>
struct SAM{
    struct State{
        int fa;                 // 后缀链接 (suffix link)
        int len;                // 该状态代表的最长子串长度
        std::array<int,N> next; // 转移边
        State(): fa(0), len(0) {next.fill(0);}
    };
    
    std::vector<State> st;
    std::vector<int> occ;  // 出现次数
    int last = 1;

    SAM(){
        init();
    }
    SAM(std::string& str){
        init();
        for(auto ch : str){
            extend(ch);
        }
    }

    void init(){
        st.resize(2);
        occ.assign(2,0);
        st[0].len = -1;
        st[1].len = st[1].fa = 0;
    }

    void extend(char ch){
        int c = ch - 'a';
        int cur = st.size(),p = last;
        st.push_back(State());
        occ.push_back(1);
        st[cur].len = st[last].len + 1;

        while(p && !st[p].next[c]){
            st[p].next[c] = cur;
            p = st[p].fa;
        }
        
        if(!p){
            st[cur].fa = 1;
        }
        else{
            int q = st[p].next[c];
            if(st[p].len + 1 == st[q].len){
                st[cur].fa = q;
            }
            else{
                int clone = st.size();
                st.push_back(st[q]);
                occ.push_back(0);
                st[clone].len = st[p].len + 1;
                while(p && st[p].next[c] == q){
                    st[p].next[c] = clone;
                    p = st[p].fa;
                }
                st[q].fa = st[cur].fa = clone;
            }
        }
        last = cur;
    }
};

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    std::string str;
    std::cin >> str;
    SAM sam(str);
    
    i64 ans = 0;
    int n = sam.st.size() - 1;
    std::vector<int> order(n + 1);
    std::iota(order.begin(),order.end(),0);
    std::sort(order.begin(),order.end(),[&](int a,int b){
        return sam.st[a].len > sam.st[b].len;
    });
    for(auto v : order){
        if(v == 0) continue;
        int fa = sam.st[v].fa;
        if(fa > 0) sam.occ[fa] += sam.occ[v];
    }
    for(int v = 2;v <= n;v++){
        if(sam.occ[v] >= 2){
            ans = std::max(ans,1LL * sam.occ[v] * sam.st[v].len);
        }
    }

    std::cout << ans << "\n";
	return 0;
}