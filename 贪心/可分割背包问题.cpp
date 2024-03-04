#include<bits/stdc++.h>
#define debug(x) cout << "#x" << x << endl;
#define all(x) (x).begin(),(x).end()
using namespace std;

//P2240 部分背包问题

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e5 + 10;

struct va{
	ll v;
	ll m;
}goods[110];

bool cmp(va a,va b){
	return a.v * b.m > b.v * a.m;
}

int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,t,sum = 0;
	double suv = 0;
	cin >> n >> t;
	for(int i = 0;i < n;i++){
		cin >> goods[i].m >> goods[i].v;
	}
	sort(goods,goods + n,cmp);
	for(int i = 0;i < n && sum <= t;i++){
		if(sum + goods[i].m <= t){
			sum += goods[i].m;
			suv += goods[i].v;
		}
		else{
			suv += goods[i].v * 1.0 / goods[i].m * (t - sum);
			break;
		}
	}
	printf("%.2f",suv);
    return 0;
}
