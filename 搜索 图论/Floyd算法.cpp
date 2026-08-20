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

void floyd(){
	for(k = 1;k <= n;k++){ 
		for(int i = 1;i <= n;i++){ 
			for(int j = 1;j <= n;j++){
				dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
			}
		}
	}
} 

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = inf;
			
	while(m--){
		cin >> x >> y >> z;
		dist[x][y] = min(dist[x][y],z);
		dist[y][x] = min(dist[y][x],z);
	}		
	
	floyd();
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
} 
