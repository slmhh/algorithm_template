#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10,mod = 1e6 + 7;
const double eps = 1e-8;

struct Point{
    double x,y,ang;
    Point operator-(Point& p){
        return {x - p.x,y - p.y,0};
    }
}p[N];

double dist(Point a,Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cross(Point a,Point b){
    return a.x * b.y - a.y * b.x;
}

bool cmp(Point a,Point b){
    if(abs(a.ang - b.ang) <= eps){
        return dist(a,p[1]) < dist(b,p[1]);
    }
    return a.ang < b.ang;
}

ll sta[N],top;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,temp;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> p[i].x >> p[i].y;
    }
    for(int i = 2;i <= n;i++){
        if(p[i].y < p[1].y || (p[i].y == p[1].y && p[i].x < p[i].x)){
            swap(p[i],p[1]);
        }
    }
    for(int i = 2;i <= n;i++){
        p[i].ang = atan2(p[i].y - p[1].y,p[i].x - p[1].x);
    }
    sort(p + 2,p + n + 1,cmp);
    sta[++top] = 1;
    for (int i = 2; i <= n; ++i) {
        while (top >= 2 && cross(p[sta[top]] - p[sta[top - 1]], p[i] - p[sta[top]]) < 0) {
            top--;
        }
        sta[++top] = i;
    }
    double ans = dist(p[sta[top]],p[1]);
    while(top >= 2){
        ans += dist(p[sta[top]],p[sta[top - 1]]);
        top--;
    }
    cout << fixed << setprecision(2) << (ll)(ans * 100 + 0.5) * 1.0 / 100 << "\n";
	return 0;
}
 