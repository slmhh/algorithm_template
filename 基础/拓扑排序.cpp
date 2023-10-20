#include<stdio.h>
#include<map>
#include<queue>
#include<string.h>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int h[N],e[N],ne[N],idx;
int d[N];//入度 
int ans[N],top;

/*思路
1. 看这个图是否有环，如果没有环就一定存在拓扑序列
2. 求出每个点的入度
3. 把所有入度为 0 的点入队
4. 枚举每一条边，删除它就是让 d[j] --;
5. 当入度为 0 时，说明前面的点都已经有序，将当前点入队
6. 当所有点都入队时说明存在拓扑序列
*/ 

void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
} 

void topsort(){
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(!d[i]){
			q.push(i);
			ans[++top] = i;
		}
	}
	while(q.size()){
		int t = q.front();
		q.pop();
		for(int i = h[t]; ~i;i = ne[i]){
			int j = e[i];
			if(--d[j] == 0){
				q.push(j);
				ans[++top] = j;
			}
		}
	}	
}

int main(){
	memset(h,-1,sizeof(h));
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		d[b]++;
	}
	topsort();
	if(top != n) puts("-1");
	else{
		for(int i = 1;i <= n;i++){
			printf("%d ",ans[i]);
		}	
	}
	return 0;
}

/*
3 3
1 2
2 3
1 3

1 2 3*/

