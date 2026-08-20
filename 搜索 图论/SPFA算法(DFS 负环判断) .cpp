#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

//P3385 【模板】负环
typedef long long ll;
typedef pair<int,int> PII;
const int N = 1e6 + 10;
ll inf = (1 << 31) - 1;

struct edge{
	ll weight;  //权重 
	ll next;   //邻接表的下一项 
	ll to;   //指向的边 
}e[N];

ll head[N]; //头节点为位置 
ll dist[N]; //节点i到起点的距离
bool st[N]; //st[i]表示该节点是否确定了最小距离，1为true，0为false
ll n,m; //n个点，m条边
ll idx = 0;
ll flag = 0;

//边:a->b,权重为c
void add(int a,int b,int c){
	e[idx].to = b;//指向的边 
	e[idx].next = head[a];
	e[idx].weight = c; //权重 
	head[a] = idx; //插入 
	idx++;
} 


void spfa(ll a){
	if(flag == 1) return;
	st[a] = true; //节点入栈
	for(ll i = head[a]; i != 0;i = e[i].next){
		if(flag == 1) return;
		if(dist[a] + e[i].weight < dist[e[i].to]){
			dist[e[i].to] = dist[a] + e[i].weight;
			if(!st[e[i].to]){ //如果指向的点没遍历过 
				spfa(e[i].to); //深搜
			}
			else{ //否则
				flag = 1;
				return; //有负环
			}
		}
	}
	st[a] = false; //将当前结点退栈
}

int main(){
	ll T;
	cin >> T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		flag = 0;
		for(ll i = 0;i <= n + 3;i++){
			head[i] = -1;
			dist[i] = inf;
			st[i] = false;
			idx = 0;
		}
		
		while(m--){
			ll x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			if(z >= 0) add(y,x,z);
			add(x,y,z);
		}
		
		dist[1] = 0;	
		spfa(1);
		
		if(flag == 1) puts("YES");
		else puts("NO");
	}
	return 0;
}
 
