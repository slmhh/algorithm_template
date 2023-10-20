#include<bits/stdc++.h>
#define debug(x) cout << "#x" << x << endl;
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10;

ll dp[2][2010];
/*
替换/跳过	删除
   插入		当前
*/
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a,b;
	cin >> a >> b;
	for(int i = 1;i <= b.size();i++)
		dp[0][i] = i;

	for(int i = 1;i <= a.size();i++){			dp[1][0] = i;
		dp[0][0] = i - 1;
		for(int j = 1;j <= b.size();j++){
			if(a[i - 1] == b[j - 1])
				dp[1][j] = dp[0][j - 1];
			else
				dp[1][j] = min(min(dp[0][j],dp[0][j - 1]),dp[1][j - 1]) + 1;
		}
		
		for(int j = 1;j <= b.size();j++){
			dp[0][j] = dp[1][j];
		}
	}

	cout << dp[1][b.size()] << "\n";
	return 0;
}
