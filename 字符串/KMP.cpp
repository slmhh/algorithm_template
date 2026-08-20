#include<bits/stdc++.h>
const int N = 1e6 + 10;
using i64 = long long;

i64 ne[N],m,n;
std::string a,b;
std::vector<i64> ans;
void getnext(std::string& str){
	ne[0] = 0;
	for(int i = 1,j = 0;i < str.size();i++){
		while(j && str[i] != str[j]) j = ne[j - 1];
		if(str[i] == str[j]) j++;
		ne[i] = j;
	}
}

void kmp(std::string& a,std::string& b){
	getnext(b);
	for(int i = 0,j = 0;i < a.size();i++){
		while(j && a[i] != b[j]) j = ne[j - 1];
		if(a[i] == b[j]) j++;
		if(j == b.size()) ans.push_back(i - b.size() + 2);
	}
}

int main(){
	std::cin.tie(0)->sync_with_stdio(0);
	std::cin >> a >> b;
	kmp(a,b);
	for(auto i : ans) std::cout << i << "\n";
	for(int i = 0;i < b.size();i++) std::cout << ne[i] << " ";
	return 0;
}
