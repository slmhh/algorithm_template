#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 4e6 + 10;
const double pi = acos(-1.0);

complex<double> f[N], g[N];
int R[N];
void change(complex<double> A[],ll n){
	for(int i = 0;i < n;i++)
		R[i] = R[i / 2] / 2 + (i & 1) * (n / 2);
	for(int i = 0;i < n;i++)
		if(i < R[i]) swap(A[i],A[R[i]]);
}

void FFT(complex<double> A[],ll n,int op){ //op为虚部符号，op为1时FFT，op为-1时IFFT
	change(A,n); //位逆序变换
	for(int m = 2;m <= n;m <<= 1){  //枚举位宽 
		complex<double> w1({cos(2 * pi / m),sin(2 * pi / m) * op});
		for(int i = 0;i < n;i += m){  //枚举块数 
			complex<double> wk({1,0});
			for(int j = 0;j < m / 2;j++){
				complex<double> x = A[i + j],y = A[i + j + m / 2] * wk;
				A[i + j] = x + y;
				A[i + j + m / 2] = x - y;
				wk = wk * w1;
			}
		}
	} 
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;
	cin >> n >> m;
	for(ll i = 0;i <= n;i++) cin >> f[i];
	for(ll i = 0;i <= m;i++) cin >> g[i];
	ll len = 1 << max((ll)ceil(log2(n + m)),1LL);  //FFT需要项数为2的整数次方倍,len为第一个大于a.size() + b.size()的二的正整数次方
	FFT(f,len,1),FFT(g,len,1);  //系数表达转点值表达
	for(int i = 0;i <= len;i++)
		f[i] = f[i] * g[i];
	FFT(f,len,-1);  //点值表达转系数表达
	for(ll i = 0;i <= m + n;i++)
		cout << (ll)(f[i].real() / len + 0.5) << " ";
	return 0;
}