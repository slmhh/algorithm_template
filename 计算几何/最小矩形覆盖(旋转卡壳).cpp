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

i64 operator^(const Vector& a,const Vector& b){
	return a[0] * b[0] + a[1] * b[1];
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

//最小矩形覆盖O(N)
i64 MRC(std::vector<Point>& points){
	i64 j = 1,l = 0,r = 0,ans = 1e18,m = points.size();
	if(m <= 2) return 0;
	for(int i = 0;i < m;i++){ //需要枚举边而不是点
		int las = i == 0 ? m - 1 : i - 1;
		//通过叉乘算三角形面积来替代点到直线距离
		while(std::abs((points[las] - points[j]) * (points[las] - points[i])) <=
			std::abs((points[las] - points[(j + 1) % m]) * (points[las] - points[i]))) j = (j + 1) % m;
		//通过点乘投影来判断长度
		while(((points[i] - points[las]) ^ (points[r] - points[las])) <=
			((points[i] - points[las]) ^ (points[(r + 1) % m] - points[las]))) r = (r + 1) % m;
		if(i == 0) l = r;
		while(((points[las] - points[i]) ^ (points[l] - points[i])) <=
			((points[las] - points[i]) ^ (points[(l + 1) % m] - points[i]))) l = (l + 1) % m;

		i64 t1 = std::abs((points[las] - points[j]) * (points[i] - points[j]));
		i64 t2 = std::abs((points[r] - points[las]) ^ (points[i] - points[las])) + 
				 std::abs((points[l] - points[i]) ^ (points[las] - points[i]));
		i64 t3 = std::abs((points[las] - points[i]) ^ (points[las] - points[i]));
		ans = std::min<i64>(ans,(__int128)t1 * (t2 - t3) / t3);
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	int n;
	std::cin >> n;
	Convex t;
	for(int i = 1;i <= n;i++){
		double x,y;
		std::cin >> x >> y;
		t.addPoint((i64)(x * 1000000),(i64)(y * 1000000));
	}
	t.work();
	std::cout << std::fixed << std::setprecision(10) << (double)MRC(t.convex) / 1e12 << "\n";
	return 0;
}