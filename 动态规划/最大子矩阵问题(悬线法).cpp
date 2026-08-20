#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e2 + 10,mod = 1e9 + 7;

int c[N][N],u[N][N],r[N][N],l[N][N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cin >> c[i][j];

	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(c[i][j]) u[i][j] = u[i - 1][j] + 1;
			if(c[i][j]) l[i][j] = l[i][j - 1] + 1;
		}
	}

	for(int i = 1;i <= n;i++)
		for(int j = m;j >= 1;j--)
			if(c[i][j]) r[i][j] = r[i][j + 1] + 1;

	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(c[i][j]){
				if(c[i - 1][j]){
					r[i][j] = min(r[i][j],r[i - 1][j]);
					l[i][j] = min(l[i][j],l[i - 1][j]);
				}
			}
			ans = max(ans,min(r[i][j] + l[i][j] - 1,u[i][j]));
			//ans = max(ans,r[i][j] + l[i][j] - 1 * u[i][j]);//最大矩形
			//ans = max(ans,min(r[i][j] + l[i][j] - 1,u[i][j]) * min(r[i][j] + l[i][j] - 1,u[i][j])); //最大正方形
        }
	}
	cout << ans << "\n";
	return 0;
}
