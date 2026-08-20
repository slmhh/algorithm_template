#include<bits/stdc++.h>
using i64 = long long;

struct ST{
	std::vector<std::vector<i64>> st;
	i64 N,op;
	ST(std::vector<i64>& s,int op){
		N = s.size();
		st.resize(N + 1,std::vector<i64>(20,-1e18));
		for(int i = 1;i < N;i++){
			st[i][0] = s[i];
		}
		this->op = op;
		build_st(op);
	}

	i64 opt1(const i64 a,const i64 b){return std::max(a,b);}
	i64 opt2(const i64 a,const i64 b){return std::min(a,b);}

	i64 query(i64 l,i64 r){
		i64 k = log2(r - l + 1); 
		if(op == 1) return opt1(st[l][k],st[r - (1 << k) + 1][k]); 
		return opt2(st[l][k],st[r - (1 << k) + 1][k]); 
	}

	void build_st(int op){
		for(int j = 1;j <= 20;j++){
			for(int i = 1;i + (1 << j) - 1 <= N;i++){
				if(op == 1) st[i][j] = opt1(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
				else st[i][j] = opt2(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
};

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	i64 m,n;
	std::cin >> n >> m;
	std::vector<i64> a(n + 1);
	for(int i = 1;i <= n;i++){
		std::cin >> a[i];
	}
	ST s(a,1);
	while(m--){
		i64 l,r;
		std::cin >> l >> r;
		std::cout << s.query(l,r) << "\n";
	}
	return 0;
}
