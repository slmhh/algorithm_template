#include<iostream>
#include<string.h>
using namespace std;

const int N = 100003;

int h[N],e[N],ne[N],idx = 0;

void insert(int x){
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}

bool find(int x){
	int k = (x % N + N) % N;
	for(int i = h[k];i != -1;i++){
		if(e[i] == x)
			return true;
	}
	return false;
}

int main(){
	int n;
	scanf("%d",&n);
	memset(h,-1,sizeof(h));
	while(n--){
		char op[2];
		int x;
		scanf("%s%d",op,&x);
		if(op == "1") insert(x);
		else{
			if(find(x)) puts("Yes\n");
			else puts("No\n");
		}
	}
}
