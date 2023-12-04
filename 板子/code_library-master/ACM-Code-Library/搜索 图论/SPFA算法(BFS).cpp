#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int N = 1e6 + 10;
ll inf = (1 << 31) - 1;

struct edge{
	int weight;  //权重 
	int next;   //邻接表的下一项 
	int to;   //指向的边 
}e[N];

int head[N]; //头节点为位置 
int dist[N]; //节点i到起点的距离
bool st[N]; //st[i]表示该节点是否确定了最小距离，1为true，0为false
int n,m; //n个点，m条边
int idx = 0;
int start; //起点 

//边:a->b,权重为c
void add(int a,int b,int c){
	e[idx].to = b;//指向的边 
	e[idx].next = head[a];
	e[idx].weight = c; //权重 
	head[a] = idx; //插入 
	idx++;
} 


void spfa(){
	for(int i = 0;i <= n + 1;i++){//初始化
		dist[i] = 0x3f3f3f3f;
	} 
	dist[start] = 0;//源点到自身距离为0
	
	queue<PII> q;
	q.push({0,start});//源点入队
	st[start] = true;
	
	while(!q.empty()){//初始化
		PII p = q.front();//取出队首元素弹出
		q.pop();
		ll temp = p.second;
		st[temp] = false; //从队列中取出来之后该节点st被标记为false,代表之后该节点如果发生更新可再次入队
		for(ll i = head[temp]; i != -1;i = e[i].next){
			ll j = e[i].to;
			if(dist[j] > dist[temp] + e[i].weight){/如果不满足三角形不等式
				dist[j] = dist[temp] + e[i].weight;//更新答案
				if(!st[j]){//如果终点不在队列
					st[j] = true;
					q.push({dist[j],j});//入队
				}
			}
		}
	}
}

int main(){
	
	cin >> n >> m >> start;
	
	memset(head,-1,sizeof(head));
	
	while(m--){
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z);
	}
			
	spfa();
		
	for(int i = 1;i <= n;i++){
		if(dist[i] == 0x3f3f3f3f)
			cout << inf << " ";
		else
			cout << dist[i] << " ";
	}
	cout << endl;
	return 0;
}
 
