#include<bits/stdc++.h>
using namespace std;

//P5788 ¡¾Ä£°å¡¿µ¥µ÷Õ»
typedef long long ll;
const int N = 1e6 + 10;

ll nums[N],ans[N];
stack<ll> up;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0;i < n;i++) cin >> nums[i];
	for(int i = n - 1;i >= 0;i--){
		while(!up.empty() && nums[i] >= nums[up.top()]) up.pop();
		if(up.empty()) ans[i] = 0;
		else ans[i] = up.top() + 1;
		up.push(i);
	}
	for(int i = 0;i < n;i++) cout << ans[i] << " ";
	return 0;
}
