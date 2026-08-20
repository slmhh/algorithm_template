#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
using namespace std;

const int N = 510;
int dist[N]; 
int g[N][N];
bool st[N];
int n,m;

void dijkstra(){
	memset(dist,0x3f,sizeof(dist)); 
	dist[1] = 0;
	
	int iter = n;
	while(iter--){ 
		int t = -1;
		for(int i = 1;i <= n;i++){
			if(st[i] == 0 && (t == -1 || dist[t] > dist[i]))
				t = i;
		}
		
		st[t] = true;
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
		g[x][y] = g[x][y] < z ? g[x][y] : z;
	}
			
	dijkstra();
		
	if(dist[n] == 0x3f3f3f3f)
		cout << "-1\n";
	else
		cout << dist[n] << endl;
	return 0;
}
 
