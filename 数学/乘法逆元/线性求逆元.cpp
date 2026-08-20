#include<iostream>
#include<stdio.h>
using namespace std;

//֤���� https://oi-wiki.org/math/number-theory/inverse/

long long inv[3000010] = {0};
int main() {
	int n,p;
	scanf("%d%d",&n,&p);
	inv[1] = 1;
	printf("%d\n",inv[1]);
	for(int i = 2;i <= n;i++){
		inv[i] = (long long)(p - p / i) * inv[p % i] % p;
		printf("%d\n",inv[i]);
	}
    return 0;
}
