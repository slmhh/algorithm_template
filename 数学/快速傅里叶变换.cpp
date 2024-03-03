#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 4e6 + 10;
const double pi = acos(-1.0);

complex<double> f[N], g[N];
void FFT(complex<double> *f,int n,int op){ //op为虚部符号，op为1时FFT，op为-1时IFFT
	if(n == 1) return;
	int mid = n / 2;
	complex<double> f1[mid + 1],f2[mid + 1];
	for(int i = 0;i <= n;i += 2){ //拆分多项式
		f1[i / 2] = f[i];
		f2[i / 2] = f[i + 1];
	}
	FFT(f1,mid,op),FFT(f2,mid,op);
	complex<double> w0(1,0),wn(cos(2 * pi / n),op * sin(2 * pi / n));
	for(int i = 0;i < mid;i++,w0 *= wn){
		f[i] = f1[i] + w0 * f2[i];
		f[i + n / 2] = f1[i] - w0 * f2[i];
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
