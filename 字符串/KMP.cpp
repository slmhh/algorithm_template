#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

typedef long long ll;
ll ne[N],m,n;
string a,b;
vector<ll> ans;
void getnext(string str){ //生成next数组
	ne[0] = 0;
	for(int i = 1,j = 0;i < str.size();i++){
		while(j && str[i] != str[j]) j = ne[j - 1];
		if(str[i] == str[j]) j++;
		ne[i] = j;
	}
}

void kmp(string a,string b){
	getnext(b);
	for(int i = 0,j = 0;i < a.size();i++){
		while(j && a[i] != b[j]) j = ne[j - 1];
		if(a[i] == b[j]) j++;
		if(j == b.size()) ans.push_back(i - b.size() + 2);
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> a >> b;
	kmp(a,b);
	for(auto i : ans) cout << i << "\n";
	for(int i = 0;i < b.size();i++) cout << ne[i] << " ";
	return 0;
}
