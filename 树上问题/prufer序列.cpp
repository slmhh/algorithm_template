#include<bits/stdc++.h>
using i64 = long long;

std::vector<int> treeToPrufer(int n,std::vector<int>& fa){
	std::vector<int> prufer(1),du(n + 1,1);
	for(int i = 1;i < n;i++) du[fa[i]]++;
	for(int i = 1;i < n;i++){
		int now = i;
		while(du[now] == 1){
			du[now] = 0,du[fa[now]]--;
			prufer.push_back(fa[now]);
			if(fa[now] > i) break;
			now = fa[now];
		}
	}
	return prufer;
}

std::vector<int> pruferToTree(int n,std::vector<int>& prufer){
	std::vector<int> fa(n),du(n + 1);
	for(int i = 1;i <= n - 2;i++) du[prufer[i]]++;
	int j = 1,now = 1;
	for(int i = 1;i < n && j <= n - 2;i++){
		now = i;
		while(du[now] == 0 && j <= n - 2){
			fa[now] = prufer[j];
			j++;
			du[fa[now]]--;
			if(fa[now] > i) break;
			now = fa[now];
		}
	}
	fa[now] = n;
	return fa;
}

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0); 
	i64 n,m,ans = 0;
	std::cin >> n >> m;
	if(m == 1){
		std::vector<int> fa(n);
		for(int i = 1;i <= n - 1;i++) std::cin >> fa[i];
		auto prufer = treeToPrufer(n,fa);
		for(int i = 1;i <= n - 2;i++) ans ^= (i64)i * prufer[i];
	}
	else{
		std::vector<int> prufer(n - 1);
		for(int i = 1;i <= n - 2;i++) std::cin >> prufer[i];
		auto fa = pruferToTree(n,prufer);
		for(int i = 1;i <= n - 1;i++) ans ^= (i64)i * fa[i];
	}
	std::cout << ans << "\n";
	return 0;
}