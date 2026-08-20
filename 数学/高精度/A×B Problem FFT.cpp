#include<bits/stdc++.h>
using namespace std;
const int N = 1 << 22;
const double eps = 1e-5, pi = acos(-1.0);
#define long long int;

vector<int> ans;
class BigInteger {
private:
	vector<int> num;  //从低位到高位存储每一位数字
	bool sign;        //符号位(+:false,-:true)
public:
	BigInteger() { sign = false; };
	friend istream & operator>>( istream &input,BigInteger &a);
	friend ostream & operator<<(ostream &output,BigInteger a);
	friend void mul(BigInteger a, BigInteger b); // a * b
	bool IsZero();  //判零
};

bool BigInteger::IsZero() {
	if (num.size() > 1) return false;
	if (num[0] == 0) return true;
	return false;
}


istream & operator>>( istream &input,BigInteger &a ){
	char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            a.sign = true;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        a.num.push_back(ch - '0');
        ch = getchar();
    }
    reverse(a.num.begin(),a.num.end());
	return input;
}

ostream & operator<<(ostream &output,BigInteger a){
	if(a.IsZero()){
		output << "0";
		return output;
	}
	if (a.sign) output << '-';
	for (int i = a.num.size() - 1; i >= 0; i--)
		output << a.num[i];
	return output;
}

// a * b
complex<double> f[N], g[N];
void FFT(complex<double> *f,int n,int inv){ //inv为虚部符号，inv为1时FFT，inv为-1时IFFT
	if(n == 1) return;
	int mid = n / 2;
	complex<double> f1[mid + 1],f2[mid + 1];
	for(int i = 0;i <= n;i += 2){ //拆分多项式
		f1[i / 2] = f[i];
		f2[i / 2] = f[i + 1];
	}
	FFT(f1,mid,inv),FFT(f2,mid,inv);
	complex<double> w0(1,0),wn(cos(2 * pi / n),inv * sin(2 * pi / n));
	for(int i = 0;i < mid;i++,w0 *= wn){
		f[i] = f1[i] + w0 * f2[i];
		f[i + n / 2] = f1[i] - w0 * f2[i];
	}
}

void mul(BigInteger a,BigInteger b){
	for(int i = 0;i < a.num.size();i++)  //转换为多项式
		f[i].real(a.num[i]);
	for(int i = 0;i < b.num.size();i++) 
		g[i].real(b.num[i]);
		
	int len = 1 << max((int)ceil(log2(a.num.size() + b.num.size())),1);  //FFT需要项数为2的整数次方倍,len为第一个大于a.size() + b.size()的二的正整数次方
	FFT(f,len,1),FFT(g,len,1);  //系数表达转点值表达
	for(int i = 0;i <= len;i++)
		f[i] = f[i] * g[i];
	FFT(f,len,-1);  //点值表达转系数表达
	
	double last = 0;
	for(int i = 0;i <= a.num.size() + b.num.size();i++){
		last += (int)(f[i].real() / len + 0.5);
		ans.push_back((int)last % 10);
		last /= 10;
	}
	while(ans.size() > 1 && ans.back() == 0)
		ans.pop_back();
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	BigInteger a,b;
	cin >> a >> b;
	mul(a,b);
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];
	cout << "\n";
	return 0LL;
}
