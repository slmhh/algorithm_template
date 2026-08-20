#include<bits/stdc++.h>
using i64 = long long;

template<class Info,class Tag>
struct SegmentTree{
    i64 N;
    std::vector<Info> info;
    std::vector<Tag> tag;
    SegmentTree():N(0){};
    SegmentTree(int _n,Info _v = Info()){init(_n,_v);}
    template<class T>
    SegmentTree(std::vector<T> _init){init(_init);}
    void init(int _n,Info _v = Info()){init(std::vector<Info>(_n,_v));}
    template<class T>
    void init(std::vector<T> _init){
        N = _init.size() - 1;
        info.assign(4 << std::__lg(N),Info());
        tag.assign(4 << std::__lg(N),Tag());
        std::function<void(int,int,int)> build = [&](int p,int l,int r){
            if(l == r){
                info[p] = _init[l];
                return;
            }
            int m = (l + r) >> 1;
            build(p << 1,l,m);
            build((p << 1) | 1,m + 1,r);
            push_up(p);
        };
        build(1,1,N);
    }
    void push_up(int p){
        info[p] = info[p << 1] + info[(p << 1) | 1];
    }
    void apply(int p,const Tag &v){
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push_down(int p){
        apply(p << 1,tag[p]);
        apply((p << 1) | 1,tag[p]);
        tag[p] = Tag();
    }
    void modify(int p,int l,int r,int x,int y,const Tag &v){
        if(l > y || r < x) return;
        if(x <= l && r <= y){
            apply(p,v);
            return;
        }
        push_down(p);
        i64 m = (l + r) >> 1;
        modify(p << 1,l,m,x,y,v);
        modify((p << 1) | 1,m + 1,r,x,y,v);
        push_up(p);
    }
    void modify(int l, int r, const Tag &v) {
        return modify(1,1,N,l,r,v);
    }
    Info query(int p,int l,int r,int x,int y){
        if(l > y || r < x) return Info();
        if(x <= l && r <= y) return info[p];
        push_down(p);
        i64 m = (l + r) >> 1;
        return query(p << 1,l,m,x,y) + query((p << 1) | 1,m + 1,r,x,y);
    }
    Info query(int l,int r){
        return query(1,1,N,l,r);
    }
};

struct Tag{
    std::bitset<30> cnt0,cnt1;
    bool flag = false;
    void apply(const Tag &t) & {
        if(!t.flag) return;
        flag = true;
        cnt0 = t.cnt0,cnt1 = t.cnt1;
    }
};

struct Info{
    std::bitset<30> cnt0,cnt1;
    void apply(const Tag &t) & {
        if(!t.flag) return;
        cnt0 = t.cnt0,cnt1 = t.cnt1;
    }
    
    Info operator+(const Info &other) const{
        return {cnt0 | other.cnt0,cnt1 | other.cnt1};
    }
};

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int n,m,q;
    std::cin >> n >> m >> q;
    std::vector<Info> a(m + 1);
    for(int i = 1;i <= m;i++){
        std::string str;
        std::cin >> str;
        for(int j = 0;j < n;j++){
            if(str[j] == '0') a[i].cnt0[j] = 1;
            else if(str[j] == '1') a[i].cnt1[j] = 1;
        }
    }
    SegmentTree<Info,Tag> t(a);
    int ans = 0;
    while(q--){
        int op,l,r;
        std::cin >> op;
        if(op == 0){
            std::cin >> l >> r;
            int tans = 1;
            auto [c0,c1] = t.query(l,r);
            for(int i = 0;i < n;i++){
                int cnt0 = c0[i],cnt1 = c1[i];
                if(cnt0 != 0 && cnt1 != 0) tans = 0;
                else if(cnt0 == 0 && cnt1 == 0) tans <<= 1;
            }
            ans ^= tans;
        }
        else{
            std::string str;
            std::cin >> l >> str;
            Tag tag{};
            for(int i = 0;i < n;i++){
                if(str[i] == '0') tag.cnt0[i] = 1;
                else if(str[i] == '1') tag.cnt1[i] = 1;
            }
            tag.flag = true;
            t.modify(l,l,tag);
        }
    }
    std::cout << ans << '\n';
	return 0;
}
