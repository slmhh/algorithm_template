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
		ll n,flag = 1;
		string work;
		cin >> n >> work;
		ll c[27] = {0};
		for(int i = 0;i < n;i++){
			if(c[work[i] - 'A']){
				flag = 0;
				break;
			}
			c[work[i] - 'A']++;
			while(i + 1 < n && work[i] == work[i + 1]){
				i++;
			}
		}
		if(flag == 0) puts("NO");
		else puts("YES");
	}
	return 0;
}