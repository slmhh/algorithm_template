#include<bits/stdc++.h>
using i64 = long long;

using Point = std::array<i64,2>;
using Vector = std::array<i64,2>;

Vector operator-(const Point& a,const Point& b){
	return {a[0] - b[0],a[1] - b[1]};
}

i64 operator*(const Vector& a,const Vector& b){
	return a[0] * b[1] - a[1] * b[0];
}

struct Convex{
	//逆指针
	std::vector<Point> points,convex;

	void addPoint(i64 x,i64 y){
		points.push_back({x,y});
	}

	void work(){
		std::sort(points.begin(),points.end());
        points.erase(std::unique(points.begin(),points.end()),points.end());
		std::vector<int> stk;
		stk.push_back(0);
		for(int i = 1;i < points.size();i++){
			int m = stk.size();
			while(m >= 2 && (points[stk[m - 2]] - points[stk[m - 1]]) * (points[stk[m - 1]] - points[i]) <= 0){
				m--;
				stk.pop_back();
			}
			stk.push_back(i);
		}
		int temp = stk.size();
		for(int i = points.size() - 1;i >= 0;i--){
			int m = stk.size();
			while(m > temp && (points[stk[m - 2]] - points[stk[m - 1]]) * (points[stk[m - 1]] - points[i]) <= 0){
				m--;
				stk.pop_back();
			}
			stk.push_back(i);
		}
		for(int i = 0;i < stk.size() - 1;i++)
			convex.push_back(points[stk[i]]);
	}
};

i64 dist(Point p1,Point p2){
    auto [x1,y1] = p1;
    auto [x2,y2] = p2;
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

//Furthest Pair of Points O(N)
i64 FPOP(std::vector<Point>& points){
	i64 j = 0,ans = 0,m = points.size();
	if(m == 1) return 0;
	else if(m == 2) return dist(points[0],points[1]);
	for(int i = 0;i < m;i++){ //需要枚举边而不是点
		int las = i == 0 ? m - 1 : i - 1;
		//通过叉乘算三角形面积来替代点到直线距离
		while(std::abs((points[las] - points[j]) * (points[las] - points[i])) <=
			std::abs((points[las] - points[(j + 1) % m]) * (points[las] - points[i]))) j = (j + 1) % m;
		ans = std::max({ans,dist(points[j],points[i]),dist(points[j],points[las])});
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	i64 n;
	std::cin >> n;
	Convex t;
	for(int i = 1;i <= n;i++){
		i64 x,y;
		std::cin >> x >> y;
		t.addPoint(x,y);
	}
	t.work();
	std::cout << FPOP(t.convex) << "\n";
	return 0;
}
 