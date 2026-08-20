#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll d = exgcd(b,a % b,y,x);
	y = y - (a / b) * x;
//	cout << x << " " << y << "\n"; 
	return d;
}

int main() {
   	ll a,b,x,y;
   	cin >> a >> b;
   	exgcd(a,b,x,y);
   	cout << (x % b + b) % b;
//   	cout << "x = " << x << "\ny = " << y << "\n";
    return 0;
}
