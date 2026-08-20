#include <bits/stdc++.h>
using i64 = long long;
using point = std::array<double, 2>;
using pointW = std::array<double, 3>;
const double T0 = 10000.0; //初始温度
const double q = 0.98; //退火系数
const int L = 100; //每次迭代次数
std::mt19937_64 rng{std::chrono::steady_clock::now().time_since_epoch().count()};
std::uniform_real_distribution<double> rnd(-1.0, 1.0);

point Point{}, bestPoint{};
double best = 1e18;
std::vector<pointW> points;

double dist(const point &a, const pointW &b) {
    return sqrtl((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1])) * b[2];
}

double calc(const point &p) {
    double res = 0;
    for (int i = 0; i < (int)points.size(); i++)
        res = std::max(res, dist(p, points[i]));
    return res;
}

void get_new(point &p, double T) {
    p[0] += rnd(rng) * T;
    p[1] += rnd(rng) * T;
}

void codeFire() {
    double T = T0,las = best;
    while(T > 1e-6){
        for(int i = 0; i < L; i++){
            point temp = Point;
            get_new(temp, T);
            double now = calc(temp);
            double DE = now - las;
            if(DE < 0 || exp(-DE / T) > ((rng() % 1000000) / 1000000.0)){
                Point = temp;
                las = now;
                if(now < best){
                    best = now;
                    bestPoint = Point;
                }
            }
        }
        T *= q;
    }
}

int main() {
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int n;
    std::cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        double x, y, c;
        std::cin >> x >> y >> c;
        points[i] = {x,y,c};
        Point[0] += x,Point[1] += y;
    }
    Point[0] /= n,Point[1] /= n;

    best = calc(Point);
    bestPoint = Point;
    codeFire();

    std::cout << std::fixed << std::setprecision(10) << best << "\n";
    return 0;
}
