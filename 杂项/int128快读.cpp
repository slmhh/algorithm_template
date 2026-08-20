#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10,mod1 = 998244353;
using i128 = __int128;

i128 to_128(string a){
    i128 res = 0;
    for(int i = a.size() - 1;i >= 0;i--){
        res = res * 10 + a[i] - '0';
    }
    return res;
}

std::ostream &operator<<(std::ostream &os, i128 n) {
    std::string s;
    if(n == 0) s = "0";
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string a,b,c;
    i128 n,l,r;
    cin >> a >> b >> c;
    n = to_128(a),l = to_128(b),r = to_128(c);
    cout << r << "\n";
 	return 0;
}