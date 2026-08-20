#include<bits/stdc++.h>
using i64 = long long;

//Closest Pair of Points O(n log n)
struct CPOP{
    using Point = std::array<i64,2>;
    std::vector<Point> points;   
    i64 minDist = 9e18;
    Point p1,p2; 

    i64 dist(Point p1,Point p2){
        auto [x1,y1] = p1;
        auto [x2,y2] = p2;
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }

    void addPoint(i64 x,i64 y){
        points.push_back({x,y});
    }
    //0 idx 左闭右开
    void work(i64 l,i64 r){
        if(r - l == 1) return;
        int mid = (l + r) >> 1;
        i64 midx = points[mid][0];
        work(l,mid),work(mid,r);

        std::inplace_merge(points.begin() + l,points.begin() + mid,points.begin() + r,
                        [&](Point a,Point b){return a[1] < b[1];});
        
        std::vector<Point> temp;
        for(int i = l;i < r;i++){
            if((points[i][0] - midx) * (points[i][0] - midx) < minDist) 
                temp.push_back(points[i]);
        }

        for(int i = 0;i < temp.size();i++){
            for(int j = i + 1;j < temp.size();j++){
                if((temp[i][1] - temp[j][1]) * (temp[i][1] - temp[j][1]) >= minDist) break;
                i64 d = dist(temp[i],temp[j]);
                if(d < minDist){
                    minDist = d;
                    p1 = temp[i],p2 = temp[j];
                }
            }
        }
    }

    void work(){
        std::sort(points.begin(),points.end());
        work(0,points.size());
    }
};

int main(){
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int n;
    std::cin >> n;
    CPOP t;
    for(int i = 1;i <= n;i++){
        i64 x,y;
        std::cin >> x >> y;
        t.addPoint(x,y);
    }
    t.work();
    std::cout << t.minDist << "\n";
    return 0;
}