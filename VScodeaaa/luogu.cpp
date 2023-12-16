#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PLL;
const int N = 1e5 + 7;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> nums(n);
	for(int i = 0;i < n;i++){
		cin >> nums[i];
	}
	ll cnt1 = 0,cnt2 = 0;
	while(cnt1 < n && nums[cnt1]) cnt1++;
	int i = n - 1;
	while(i >= 0 && nums[i]){
		cnt2++;
		i--;
	}
	if(cnt1 & 1 || cnt2 & 1 ) puts("YES");
	else puts("NO");
    return 0;
}