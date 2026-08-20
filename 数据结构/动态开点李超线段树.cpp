#include<bits/stdc++.h>
using i64 = long long;

struct Lichao{
    static constexpr double eps = 1e-8;
    struct Line{
        double k,b;
        int id;
        Line(double k = 0,double b = 0,int id = 0):k(k),b(b),id(id){};
        double calc(int x){return k * x + b;}
        double cross(const Line& T){return (T.b - b) / (k - T.k);}
    };

    struct Node{
        int l,r,ls,rs;
        Line L;
        bool flag;
        Node(){};
        Node(int l,int r):l(l),r(r),ls(0),rs(0),flag(false){};
    };

    std::vector<Node> tr;
    int cnt;
    int L_range,R_range;

    Lichao(int L, int R):L_range(L),R_range(R),cnt(1){
        tr.push_back(Node());
        tr.push_back(Node(L,R));
    }

    void new_node(int& p,int l,int r){
        p = ++cnt;
        tr.push_back(Node(l,r));
    }

    void update(int p,int L,int R,Line ln){
        int l = tr[p].l, r = tr[p].r;
        int mid = (l + r) >> 1;
        
        if(L <= l && r <= R){
            if(!tr[p].flag){
                tr[p].L = ln;
                tr[p].flag = true;
                return;
            }
            
            double lp = tr[p].L.calc(l),rp = tr[p].L.calc(r);
            double lq = ln.calc(l),rq = ln.calc(r);
            
            if(!tr[p].flag) tr[p].L = ln,tr[p].flag = true;
            else if(lq - lp > eps && rq - rp > eps) tr[p].L = ln;
            else if(lq - lp > eps || rq - rp > eps){
                int mid = (l + r) >> 1;
                if(ln.calc(mid) - tr[p].L.calc(mid) > eps) std::swap(tr[p].L,ln);
                if(ln.calc(l) - tr[p].L.calc(l) > eps){
                    if(!tr[p].ls) new_node(tr[p].ls,l,mid);
                    update(tr[p].ls,L,R,ln);
                }
                else{
                    if(!tr[p].rs) new_node(tr[p].rs,mid + 1,r);
                    update(tr[p].rs,L,R,ln);
                }
            }
        }
        else{
            if(L <= mid){
                if(!tr[p].ls) new_node(tr[p].ls,l,mid);
                update(tr[p].ls,L,R,ln);
            }
            if(R > mid){
                if(!tr[p].rs) new_node(tr[p].rs,mid + 1,r);
                update(tr[p].rs,L,R,ln);
            }
        }
    }

    std::pair<double,int> query(int p,int pos){
        int l = tr[p].l,r = tr[p].r;
        double ans = tr[p].L.calc(pos);
        int id = tr[p].L.id;
        if(l == r) return {ans,id};
        int mid = (l + r) >> 1;

        std::pair<double,int> tq;
        if(pos <= mid && tr[p].ls) tq = query(tr[p].ls, pos);
        else if(pos > mid && tr[p].rs) tq = query(tr[p].rs, pos);
        else tq = {-1e18,0};
        
        if(tq.first > ans || (fabs(tq.first - ans) < eps && tq.second < id))
            ans = tq.first,id = tq.second;
        return {ans,id};
    }

    std::pair<double,int> query(int x){
        return query(1,x);
    }

    void update(i64 x0,i64 y0,i64 x1,i64 y1,i64 id){
        Line ln;
        if(x0 == x1) ln = {0,std::max(y0,y1),id};
        else{
            double tk = (double)(y1 - y0) / (x1 - x0);
            double tb = y0 - tk * x0;
            ln = {tk, tb,id};
        }
        update(1,x0,x1,ln);
    }
};

int main(){
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int T = 1;
    std::cin >> T;
    i64 lasans = 0, idx = 0;
    Lichao tr(1,1E9 + 7);
    
    while(T--){
        i64 op, k, x0, y0, x1, y1;
        std::cin >> op;
        if(op == 0){
            std::cin >> k;
            k = (k + lasans - 1) % 39989 + 1;
            lasans = tr.query(k).second;
            std::cout << lasans << "\n";
        }
        else{
            std::cin >> x0 >> y0 >> x1 >> y1;
            x0 = (x0 + lasans - 1) % 39989 + 1;
            x1 = (x1 + lasans - 1) % 39989 + 1;
            y0 = (y0 + lasans - 1) % 1000000000 + 1;
            y1 = (y1 + lasans - 1) % 1000000000 + 1;
            if(x0 > x1){
                std::swap(x0, x1);
                std::swap(y0, y1);
            }
            tr.update(x0, y0, x1, y1, ++idx);
        }
    }
    return 0;
}