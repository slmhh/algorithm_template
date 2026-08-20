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

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	int T = 1;
	std::cin >> T;
	while(T--){
		int n;
		std::cin >> n;
		Convex t;
		for(int i = 1;i <= n;i++){
			i64 x,y;
			std::cin >> x >> y;
			t.addPoint(x,y);
		}
		t.work();
		std::cout << t.convex.size() << "\n";
		for(auto [x,y] : t.convex){
			std::cout << x << " " << y << "\n";
		}
	}
	return 0;
}
 