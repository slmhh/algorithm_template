#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct CarTree{
	struct node{
		int l,r;
		node():l(0),r(0){}
	};
	vector<node> tr;
	CarTree(){};
	CarTree(vector<T>& a){
		stack<T> stk;
		tr.resize(a.size());
		for(int i = 1;i < a.size();i++){
			int last = 0;
			while(!stk.empty() && a[stk.top()] > a[i]){
				last = stk.top();
				stk.pop();
			}
			if(last != 0) tr[i].l = last;
			if(!stk.empty()) tr[stk.top()].r = i;
			stk.push(i);
		}
	}
};

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	CarTree<ll> t(a);
	ll l = 0,r = 0;
	for(ll i = 1;i <= n;i++){
		l ^= i * (t.tr[i].l + 1);
		r ^= i * (t.tr[i].r + 1);
	}
	cout << l << ' ' << r << "\n";
	return 0;
}
