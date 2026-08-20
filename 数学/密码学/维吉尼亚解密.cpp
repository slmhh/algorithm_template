#include<bits/stdc++.h>
#define debug(x) cout << "#x" << x << endl;
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10;
ll inf = 0x3f3f3f3f;

ll g[1010][1010];
ll mo[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string code,key,ans = "";
	cin >> key >> code;
	for(int i = 0;i < code.size();i++){
		ll t = (key[i % key.size()] & 95) - 'A';
		if(code[i] >= 'A' && code[i] <= 'Z') ans += (code[i] - 'A' + 26 - t) % 26 + 'A';
		else ans += (code[i] - 'a' + 26 - t) % 26 + 'a';
	}
	cout << ans << "\n";
	return 0;
}
