#include<iostream>
#include<string.h>
using namespace std;

//a * x 同余 1(mod p)时，a的逆元为a^(p - 2) (mod p) 

long long qpow(long long int n,long long int p,long long mod){
	if(p == 1) return n;
	if(p % 2 == 0){
		long long int temp = qpow(n,p / 2,mod);
		return temp * temp % mod;
	}
	return qpow(n,p - 1,mod) * n % mod;
	
}


int main() {
	long long int n,p;
   	scanf("%lld %lld",&n,&p);
   	for(int i = 1;i <= n;i++){
   		printf("%lld\n",qpow(i,p - 2,p));	
	}	
    return 0;
}
