// LUOGU_RID: 114906823
#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define int long long
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin()+1, (x).end()
#define cy cout<<"Yes\n"
#define cn cout<<"No\n"
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 +7;
typedef long long ll;
int T, n, m, k, q;


signed main() {
	T=1;
//	cin>>T;
	for (; T--; ){
		cin>>n;
		vector<int> a(n+1);
		vector<int> b(N, 0);
		
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			b[x]++;
		}
		int ans = 0;
		for(int i=1; i<N; i++){
			for(int j=1; i*j<N; j++){
				ans+=b[i]*b[j]*b[i*j];
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
