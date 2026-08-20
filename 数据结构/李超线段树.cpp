#include<bits/stdc++.h>
using i64 = long long;

struct Lichao{
    #define ls (p << 1)
    #define rs ((p << 1) | 1)
    static constexpr double eps = 1e-8;
    struct line{
        double k,b;
        int id;      // 部分题需要记录线段编号
        line(double k = 0,double b = 0,int id = 0):k(k),b(b),id(id){};
        // 计算线段在pos位置的纵坐标
        double calc(int x){ return k * x + b;}
        // 求两条线段的交点横坐标
        double cross(const line& T){ return (T.b - b) / (k - T.k);}
    };

    struct node{
        int l,r;   // 区间左右端点
        line L;    // 最优线段
        bool flag; // 记录区间内是否有最优线段
        node(){};
        node(int l,int r,line L,bool flag):l(l),r(r),L(L),flag(flag){};
    };

    std::vector<node> tr;
    Lichao(){}
    Lichao(int N):tr(N << 2){
        build(1,1,N);
    };

    void build(int p,int l,int r){
        tr[p] = {l,r,line(),false};
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(ls,l,mid),build(rs,mid + 1,r);
    }

    //O(log^2 n)
    void update(int p,int L,int R,line ln){
        int l = tr[p].l,r = tr[p].r;
        if(L <= l && r <= R){ //如果插入线段的定义域覆盖整个区间
            double lp = tr[p].L.calc(l),rp = tr[p].L.calc(r);
            double lq = ln.calc(l),rq = ln.calc(r);

            if(!tr[p].flag) tr[p].L = ln,tr[p].flag = true;
            else if(lq - lp > eps && rq - rp > eps) tr[p].L = ln;
            else if(lq - lp > eps || rq - rp > eps){
                int mid = (l + r) >> 1;
                if(ln.calc(mid) - tr[p].L.calc(mid) > eps) std::swap(tr[p].L,ln);
                if(ln.calc(l) - tr[p].L.calc(l) > eps) update(ls,L,R,ln);
                else update(rs,L,R,ln);
            }
        }
        else{
            int mid = (l + r) >> 1;
            if(L <= mid) update(ls,L,R,ln);
            if(R > mid) update(rs,L,R,ln);
        }
    }

    //O(log n)
    std::pair<double,int> query(int p,int pos){ //返回最大值和线段编号
        int l = tr[p].l,r = tr[p].r;
        double ans = tr[p].L.calc(pos);
        int id = tr[p].L.id;
        if(l == r) return {ans,id};
        int mid = (l + r) >> 1;

        std::pair<double,int> tq;
        if(pos <= mid) tq = query(ls,pos);
        else tq = query(rs,pos);

        if(tq.first > ans || (fabs(tq.first - ans) < eps && tq.second < id))
            ans = tq.first,id = tq.second;
        return {ans,id};
    }

    std::pair<double,int> query(int x){
        return query(1,x);
    }

    void update(i64 x0,i64 y0,i64 x1,i64 y1,i64 id){
        line ln;
        if(x0 == x1) ln = {0,std::max(y1,y0),id};
        else{
            double tk = (double)(y1 - y0) / (x1 - x0);
            double tb = (double)(y0 - tk * x0);
            ln = {tk,tb,id};
        }
        update(1,x0,x1,ln);
    }
};

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int T = 1;
    std::cin >> T;
    i64 lasans = 0,idx = 0;
    Lichao tr(40000);
    while(T--){
        i64 op,k,x0,y0,x1,y1;
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
                std::swap(x0,x1);
                std::swap(y0,y1);
            }
            tr.update(x0,y0,x1,y1,++idx);
        }
    }
 	return 0;
}
 