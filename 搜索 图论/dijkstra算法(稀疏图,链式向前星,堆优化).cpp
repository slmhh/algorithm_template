#include<bits/stdc++.h>
using namespace std;

//无负权边 
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e6 + 10;

struct edge{
	ll next;   //邻接表的下一项 
	ll to;   //指向的边 
	ll weight;  //权重 
};

ll head[N]; //头节点为位置 
ll dist[N]; //节点i到起点的距离
bool st[N]; //st[i]表示该节点是否确定了最小距离，1为true，0为false
ll n,m; //n个点，m条边
ll idx = 0;
ll start; //起点 
vector<edge> e; 

//边:a->b,权重为c
void add(int a,int b,int c){
	e.push_back({head[a],b,c}); 
	head[a] = e.size() - 1;
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
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> start;
	memset(head,-1,sizeof(head));
	while(m--){
		ll x,y,z;
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
		cout << dist[n] << endl;*/
	return 0;
}
 
