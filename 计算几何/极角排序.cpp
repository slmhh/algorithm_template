#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e3 + 10,mod = 998244353;
const double eps = 0,pi = acos(-1);
struct node{
    ll x,y,idx;
    double dge;
};

bool cmp(node a,node b){
    return a.dge - b.dge < eps;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        ll n;
        cin >> n;
        vector<node> a(n + 1);
        for(int i = 1;i <= n;i++){
            ll x,y;
            cin >> x >> y;
            a[i] = {x,y,i,atan2(x,y)};
            if(a[i].dge < 0) a[i].dge += 2 * pi;
        }
        sort(a.begin() + 1,a.end(),cmp);
        double ans = a[1].dge - a[n].dge;
        ans += 2 * pi;
        ll idx1 = a[1].idx,idx2 = a[n].idx;
        for(int i = 1;i < n;i++){
            double temp = a[i + 1].dge - a[i].dge;
            if(temp - ans < eps){
                ans = temp;
                idx1 = a[i + 1].idx,idx2 = a[i].idx;
            } 
        }
        cout << idx1 << " " << idx2 << "\n";
    }
	return 0;
}