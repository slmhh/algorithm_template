#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N = 110;
//queue<pair<int,int>> q; //坐标;
pair<int,int> q[N*N];
int d[N][N]; //到起点的距离 
int ma[N][N]; //地图 
int m,n;  //地图size
pair<int,int> prv[N][N];//从哪个点过来的,路径记录
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1}; //向四个方向移动 


int bfs(){
	//q.push(0,0);
	int hh = 0,tt = 0;
	q[0] = {0,0};
	
	memset(d,-1,sizeof(d));  //d没走过
	d[0][0] = 0;  //起点
	
	while(/*!q.empty()*/  hh <= tt){
		//pair<int,int> temp = q.back();
		pair<int,int> t = q[hh++];
		
		for(int i = 0;i < 4;i++){
			int x = t.first + dx[i],y = t.second + dy[i];
			//     x是否越界         y是否越界      此处是否能走     此处是否走过 
			if(x >= 0 && x < n && y >= 0 && y < m && ma[x][y] == 0 && d[x][y] == -1){
				d[x][y] = d[t.first][t.second] + 1;  //比前一个点多一
				//q.push(x,y);
				q[++tt] = {x,y};
				prv[x][y] = t;
			}
		}
	}
	int x = n - 1,y = m - 1;
	while(x || y){
		printf("%d %d",x,y);
		pair<int,int> t = prv[x][y];
		x = t.first;
		y = t.second;
	}
	return d[n - 1][m - 1]; //终点距离 
}


int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			scanf("%d",ma[i][j]);
	
	printf("%d\n",bfs());
	return 0;
}
