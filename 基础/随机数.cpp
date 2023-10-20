#include<bits/stdc++.h>
#define debug(x) cout << "#x" << x << endl;
#define all(x) (x).begin(),(x).end()
using namespace std;

//B3800 [NICA #1] µ¯Ä»
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10;

ll a[N],b[N],c[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,flag = 1,ans,t;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> b[i] >> c[i];
	}

	srand(time(0));

	while(true){
		t = rand() % 1000001;
		flag = 1;
		for(int i = 0;i < n;i++){
			if(t * t * t + a[i] * t * t + b[i] * t + c[i] == 0){
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			ans = t;
			break;
		}
	}
	cout << ans << "\n";
    return 0;
}
