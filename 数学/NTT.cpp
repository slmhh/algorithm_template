#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
static constexpr int N = 4e6 + 6;
static constexpr int  g = 3,mod = 998244353;
i64 ni,gi;

i64 qpow(i64 a,i64 b){
    i64 ans = 1;
    for(;b;a = a * a % mod,b >>= 1)
        if(b & 1) ans = ans * a % mod;
    return ans;
}

void NTT(vector<i64>& A,int n,int op){
    vector<i64> R(n + 1,0);
	for(int i = 0;i < n;i++)
		R[i] = R[i / 2] / 2 + (i & 1) * (n / 2);
	for(int i = 0;i < n;i++)
		if(i < R[i]) swap(A[i],A[R[i]]);

	for(int i = 2;i <= n;i <<= 1){
        i64 g1 = qpow(op == 1 ? g : gi,(mod - 1) / i);
        for(int j = 0;j < n;j += i){
            i64 gk = 1;
            for(int k = j;k < j + i / 2;k++){
                i64 x = A[k],y = gk * A[k + i / 2] % mod;
                A[k] = (x + y) % mod;
                A[k + i / 2] = (x - y + mod) % mod;
                gk = gk * g1 % mod;
            }
        }
    }
}

void clac(vector<i64>& a,vector<i64>& b){
    const int la = a.size(),lb = b.size();
	int len = 1 << max((int)ceil(log2(la + lb)),1);
    vector<i64> f(3 * len + 1,0),h(3 * len + 1,0);
	for(int i = 0;i < la;i++) f[i] = a[i];
	for(int i = 0;i < lb;i++) h[i] = b[i];
    gi = qpow(g,mod - 2),ni = qpow(len,mod - 2);
	NTT(f,len,1),NTT(h,len,1);
	for(int i = 0;i <= len;i++) 
        f[i] = (f[i] * h[i]) % mod;
	NTT(f,len,-1);
	for(int i = 0;i <= la + lb - 2;i++) 
        cout << (f[i] * ni) % mod << " ";
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    i64 n,m;
    cin >> n >> m;
    vector<i64> a(n + 1),b(m + 1);
    for(int i = 0;i <= n;i++) cin >> a[i];
    for(int i = 0;i <= m;i++) cin >> b[i];
    clac(a,b);
    return 0;
}