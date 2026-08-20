#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	//T = 1;
	while(T--){
		ll n;
        cin >> n;
        if(n / 2 % 2 == 1){
            cout << "NO\n";
            continue;
        }
        ll sum = 0;
        cout << "YES\n";
        for(int i = 1;i <= n / 2;i++){
            cout << i * 2 << " ";
            sum += i * 2;
        }
        for(int i = 0;i < n / 2 - 1;i++){
            cout << i * 2 + 1<< " ";
            sum -= i * 2 + 1;
        }
        cout << sum << "\n";
	}
	return 0;
}
