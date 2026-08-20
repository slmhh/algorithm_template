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


void spfa(){
	for(int i = 0;i <= n + 1;i++){
		dist[i] = 0x3f3f3f3f;
	} 
	dist[start] = 0;
	
	queue<PII> q;
	q.push({0,start});
	st[start] = true;
	
	while(!q.empty()){
		PII p = q.front();
		q.pop();
		ll temp = p.second;
		st[temp] = false; 
		for(ll i = head[temp]; i != -1;i = e[i].next){
			ll j = e[i].to;
			if(dist[j] > dist[temp] + e[i].weight){
				dist[j] = dist[temp] + e[i].weight;
				if(!st[j]){
					st[j] = true;
					q.push({dist[j],j});
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
 
