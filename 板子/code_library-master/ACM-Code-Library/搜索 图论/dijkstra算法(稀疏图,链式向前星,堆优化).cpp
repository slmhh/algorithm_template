#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

//无负权边 
typedef pair<int,int> PII;
const int N = 1e6 + 10;

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


void dijkstra(){
	priority_queue <PII,vector<PII>,greater<PII> > heap;
	heap.push({0,start}); //first为距离，second为节点 
	
	memset(dist,0x3f,sizeof(dist));  //把距离初始化为正无穷
	dist[start] = 0; //起点为1
	 
	while(heap.size()){
		PII t = heap.top();
		heap.pop();
		
		int ver = t.second,d = t.first;
		if(st[ver] == 1) continue;
		st[ver] = 1;
		
		//a -> b,已知a的距离和边权，去更新b的距离
		for(int i = head[ver];i != -1;i = e[i].next){
			int j = e[i].to; //指向的边 
			if(dist[j] > d + e[i].weight){
				dist[j] = d + e[i].weight;
				heap.push({dist[j],j});
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
			
	dijkstra();
		
	for(int i = 1;i <= n;i++){
		cout << dist[i] << " ";
	}
	/*if(dist[n] == 0x3f3f3f3f)
		cout << "-1\n";
	else
		cout << dist[n] << endl;
	return 0;*/
}
 
