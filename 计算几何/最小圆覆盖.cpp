#include<bits/stdc++.h>
using i64 = long long;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
static constexpr double eps = 1e-9;
using Point = std::array<double,2>;

double dist(Point& a,Point& b){
	return std::sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}

//Smallest enclosing circle 期望O(N)，最坏O(h^3 n)
struct SEC{
	std::vector<Point> points;
	double r = 0;
	Point o{};
	void addPoint(double x,double y){
		points.push_back({x,y});
	}

	void update(Point& x,Point& y){
		o[0] = (x[0] + y[0]) / 2;
		o[1] = (x[1] + y[1]) / 2;
		r = dist(x,y) / 2;
	}

	Point geto(Point a,Point b,Point c){
		double a1,a2,b1,b2,c1,c2;
		Point res;
		a1 = 2 * (b[0] - a[0]), b1 = 2 * (b[1] - a[1]),
		c1 = b[0] * b[0] - a[0] * a[0] + b[1] * b[1] - a[1] * a[1];
		a2 = 2 * (c[0] - a[0]), b2 = 2 * (c[1] - a[1]),
		c2 = c[0] * c[0] - a[0] * a[0] + c[1] * c[1] - a[1] * a[1];
		if(std::fabs(a1) <= eps){
			res[1] = c1 / b1;
			res[0] = (c2 - res[1] * b2) / a2;
		}
		else if(std::fabs(b1) <= eps){
			res[0] = c1 / a1;
			res[1] = (c2 - res[0] * a2) / b2;
		}
		else{
			res[0] = (c2 * b1 - c1 * b2) / (a2 * b1 - a1 * b2);
			res[1] = (c2 * a1 - c1 * a2) / (b2 * a1 - b1 * a2);
		}
		return res;
	}

	void work(){
		int n = points.size();
		for(int i = 0;i < n;i++) std::swap(points[rng() % n],points[rng() % n]);
		o = points[0];
		for(int i = 0;i < n;i++){
			if(dist(o,points[i]) - r < eps) continue;
			update(points[i],points[0]);
			for(int j = 0;j < i;j++){
				if(dist(o,points[j]) - r < eps) continue;
				update(points[i],points[j]);
				for(int k = 0;k < j;k++){
					if(dist(o,points[k]) - r < eps) continue;
					o = geto(points[i],points[j],points[k]);
					r = dist(o,points[i]);	
				}
			}
		}
	}
};

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	int n;
	std::cin >> n;
	SEC circ;
	for(int i = 1;i <= n;i++){
		double x,y;
		std::cin >> x >> y;
		circ.addPoint(x,y);
	}
	circ.work();
	std::cout << std::fixed << std::setprecision(10) << circ.r << "\n" << circ.o[0] << " " << circ.o[1] << "\n";
	return 0;
}