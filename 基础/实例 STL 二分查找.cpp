#include<bits/stdc++.h>
#define debug(x) cout << "#x" << x << endl;
#define all(x) (x).begin(),(x).end()
using namespace std;

//Å£¿Í  Ó¢Óï×÷ÎÄ 
typedef long long ll;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
ll inf = 0x3f3f3f3f;

int main(){
	int T;
	//cin >> T;
	T = 1;
	while(T--){
		ll n,k,cnt = 0;
        string word;
        map<string,vector<ll> > w;
        cin >> n >> k;
        for(int i = 0;i < n;i++){
            cin >> word;
            cnt += w[word].end() - lower_bound(w[word].begin(),w[word].end(),i - k - 1);
            w[word].push_back(i);
        }
        cout << cnt << endl;
	}
	return 0;
}
