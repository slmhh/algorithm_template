#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10;

string bin[100];
void creat(){
	string temp;
	ll t,t1 = 1;
	for(ll i = 0;i <= 62;i++,t1 *= 2){
		temp = "";
		t = t1;
		while(t > 0){
			temp = char(t % 10 + '0') + temp;
			t /= 10;
		}
		bin[i] = temp;
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll T;
	cin >> T;
	//T = 1;
	creat();
	while(T--){
		string k;
		cin >> k;
		ll sum = 0,ans = 0x3f3f3f3f3f;
		for(int i = 0;i <= 62;i++){
			sum = 0;
			for(int j = 0;j < k.size();j++){
				//求最长相同前缀
				if(k[j] == bin[i][sum]) sum++;
			}
			if(ans > k.size() + bin[i].size() - 2 * sum){
				ans = k.size() + bin[i].size() - 2 * sum;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}