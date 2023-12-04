#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
using namespace std;

//无负权边 

const int N = 510;
int dist[N]; //节点i到起点的距离
int g[N][N];  //节点i到节点j边的长度，稠密图用邻接矩阵来存储
bool st[N]; //st[i]表示该节点是否确定了最小距离，1为true，0为false
int n,m; //n个点，m条边

void dijkstra(){
	memset(dist,0x3f,sizeof(dist));  //把距离初始化为正无穷
	dist[1] = 0;
	
	int iter = n;
	while(iter--){  //n个点，循环n次 
		int t = -1;
		//表示未确定最小距离的节点，且为所有未确定节点中最小 
		for(int i = 1;i <= n;i++){
			if(st[i] == 0 && (t == -1 || dist[t] > dist[i]))
				t = i;
		}
		
		st[t] = true;
		//用节点t依次更新其他节点到起点的最短距离
		for(int i = 1;i <= n;i++){
			if(st[i] == 0){
				dist[i] = (dist[i] > dist[t] + g[t][i]) ? (dist[t] + g[t][i]) : dist[i];
			}
		} 
	}
}

int main(){
	
	cin >> n >> m;
	
	memset(g,0x3f,sizeof(g));
	while(m--){
		int x,y,z;
		cin >> x >> y >> z;
		g[x][y] = g[x][y] < z ? g[x][y] : z; //存在重边
		//对于自环，由于不影响计算，所以不做处理 
	}
			
	dijkstra();
		
	if(dist[n] == 0x3f3f3f3f)
		cout << "-1\n";
	else
		cout << dist[n] << endl;
	return 0;
}
 
