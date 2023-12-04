#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int N = 210,M = 2e4 + 10,inf = 0x3f3f3f;

int n,m,k,x,y,z;
int dist[N][M];


//d[i][j] 表示点i到点j的最短距离 ,k为中间点 
void floyd(){
	for(k = 1;k <= n;k++){   //枚举中间点 
		for(int i = 1;i <= n;i++){ //起始点 
			for(int j = 1;j <= n;j++){ //目的地 
				dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
			}
		}
	}
} 

int main(){
	cin >> n >> m;
	//距离初始化 
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = inf;
			
	//x -> y,权重为z 
	while(m--){
		cin >> x >> y >> z;
		dist[x][y] = min(dist[x][y],z);
		dist[y][x] = min(dist[y][x],z); //无向图 
	}		
	
	floyd();
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
} 
