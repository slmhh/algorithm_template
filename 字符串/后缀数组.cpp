#include<bits/stdc++.h>
using i64 = long long;

struct SA{
	std::string str;
	int n,m,tp = 128,p = 0;
	std::vector<int> rk,sa;
	SA(std::string _s){
		str = " " + _s;
		n = _s.size();
		m = (n << 1) + 1;
		rk.assign(m,0),sa.assign(m,0);
		work();
	};

	void work(){
		if(n == 1){
			sa[1] = rk[1] = 1;
			return;
		}

		std::vector<int> cnt(std::max(tp,n) + 1),id(n + 1);
		for(int i = 1;i <= n;i++) cnt[rk[i] = str[i]]++;									
		for(int i = 1;i <= tp;i++) cnt[i] += cnt[i - 1];
		for(int i = n;i >= 1;i--) sa[cnt[rk[i]]--] = i;

		for(int w = 1;w < n;w <<= 1,tp = p){
			int cur = 0;
			for(int i = n - w + 1;i <= n;i++) id[++cur] = i;
			for(int i = 1;i <= n;i++)
				if(sa[i] > w) id[++cur] = sa[i] - w;
			std::fill(cnt.begin(),cnt.end(),0);
			for(int i = 1;i <= n;i++) cnt[rk[i]]++;
			for(int i = 1;i <= tp;i++) cnt[i] += cnt[i - 1];
			for(int i = n;i >= 1;i--) sa[cnt[rk[id[i]]]--] = id[i];

			std::vector<int> temp(m);
			p = 0;
			for(int i = 1;i <= n;i++){
				if(rk[sa[i]] != rk[sa[i - 1]] || rk[sa[i] + w] != rk[sa[i - 1] + w]) p++;
				temp[sa[i]] = p; 
			}
			rk = temp;

			if(p == n) break;
		}
	}

};

int main(){
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	std::string str;
	std::cin >> str;
	SA s(str);
	for(int i = 1;i <= str.size();i++){
		std::cout << s.sa[i] << " ";
	}
	return 0;
}