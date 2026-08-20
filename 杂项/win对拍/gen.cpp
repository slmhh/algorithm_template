#include<bits/stdc++.h>
using namespace std;

int main(){
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::cout << 1 << "\n"; 
	int l = rng() % 1000 + 1,r = rng() % 1000 + 1;
	if(l < r) std::swap(l,r);
	std::cout << l << " " << r << "\n";
//	cout << n << "\n";
//	for(int i = 1;i <= n;i++){
//		int x = rng() % 3;
//		cout << x; 
//	}
	return 0;
}
