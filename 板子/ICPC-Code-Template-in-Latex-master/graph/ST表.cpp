#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

//P3865 【模板】ST 表
//静态区间最大值
ll st[N][20],n,m; 
ll opt(const ll a,const ll b){return max(a,b);}

ll query(ll l,ll r){
    ll k = log2(r - l + 1); 
    return opt(st[l][k],st[r - (1 << k) + 1][k]); 
}

void build_st(){
	for(int j = 1;j <= 20;j++)
        for(int i = 1;i + (1 << j) - 1 <= n;i++)
            st[i][j] = opt(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> st[i][0];
	}
	build_st();
	while(m--){
		ll l,r;
		cin >> l >> r;
		cout << query(l,r) << "\n";
	}
	return 0;
}
