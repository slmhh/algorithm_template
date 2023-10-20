#include<iostream>

using namespace std;

//1.将两个集合合并
//2.访问两个集合是否在一个集合中

//接近O(1)

const int N = 100010;

int p[N]; 

int find(int x){  //返回x的祖宗节点  (路径压缩) 
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) p[i] = i;  //集合编号
	
	while(m--){
		char op[2];
		int a,b;
		scanf("%s%d%d",op,&a,&b);
		
		if(op[0] == 'M') p[find(a)] = find(b);  //合并集合
		
		else{
			if(find(a) == find(b)) printf("Yes\n");
			else printf("No\n");
		} 
	} 
	return 0;
}
 
