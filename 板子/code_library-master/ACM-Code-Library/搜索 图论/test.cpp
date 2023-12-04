#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> PII;
const int N = 1e6 + 10;
const long long inf=2147483647;

struct edge{
	int weight; 
	int next;   
	int to;   
}e[N];

int head[N]; 
int dist[N];
bool st[N]; 
int n,m; 
int idx = 0;
int start; 

void add(int a,int b,int c){
	e[idx].to = b;
	e[idx].next = head[a];
	e[idx].weight = c; 
	head[a] = idx; 
	idx++;
} 


void dijkstra(){
	priority_queue <PII,vector<PII>,greater<PII> > heap;
	heap.push({0,start}); 
	
	for(int i = 0;i <= n + 1;i++){
		dist[i] = 0x3f3f3f3f;
	}  
	dist[start] = 0;
	 
	while(heap.size()){
		PII t = heap.top();
		heap.pop();
		
		int ver = t.second,d = t.first;
		if(st[ver] == 1) continue;
		st[ver] = 1;
		
		for(int i = head[ver];i != -1;i = e[i].next){
			int j = e[i].to; 
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
		if(dist[i] == 0x3f3f3f3f)
			cout << inf << " ";
		else
			cout << dist[i] << " ";
	}
	cout << endl;
	return 0;
}
 
