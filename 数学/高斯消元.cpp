#include<bits/stdc++.h>
using i64 = long long;

static constexpr double eps = 1e-8;
int Gauss(std::vector<std::vector<double>>& a){
	int n = a.size() - 1,now = 1;
	for(int i = 1;i <= n;i++){ //枚举列
		int r = now;
		for(int j = i;j <= n;j++){ //找最大减小误差
			if(fabs(a[j][i]) > fabs(a[r][i]))
				r = j;
		}
		if(fabs(a[r][i]) < eps) continue;
		if(r != now) swap(a[now],a[r]);

		for(int j = 1;j <= n;j++){
			if(j == now) continue;
			double div = a[j][i] / a[now][i];
			for(int k = i;k <= n + 1;k++)
				a[j][k] -= a[now][k] * div;
		}
		now++;
	}
	if(now <= n){
		while(now <= n){
			if(fabs(a[now][n + 1]) > eps)
				return -1;
			now++;
		}
		return 0;
	}
	for(int i = 1;i <= n;i++) a[i][n + 1] /= a[i][i];
	return true;
} // 1 有解,-1无解,0无穷解

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<std::vector<double>> a(n + 1,std::vector<double>(n + 2));
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n + 1;j++){
			std::cin >> a[i][j];
		}
	}
	int res = Gauss(a);
	if(res == 1){
		for(int i = 1;i <= n;i++){
			std::cout << "x" << i << "=";
			std::cout << std::fixed << std::setprecision(2) << a[i][n + 1] << "\n";
		}
	}
	else std::cout << res << "\n";
	return 0;
}
 