#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll T;
	cin >> T;
	//T = 1;
	while(T--){
		ll n,l,r,cnt = 0,t;
		cin >> n >> l  >> r;
		vector<ll> nums;
		for(int i = 0;i < n;i++){
			cin >> t;
			nums.push_back(t);
		}
		sort(all(nums));
		for(int i = 0;i < n - 1;i++){
			ll a,b;
			a = lower_bound(nums.begin() + i + 1,nums.end(),l - nums[i]) - nums.begin();
			b = upper_bound(nums.begin() + i + 1,nums.end(),r - nums[i])- nums.begin();
			cnt += b - a;
		}
		cout << cnt << "\n";
	}
	return 0;
}