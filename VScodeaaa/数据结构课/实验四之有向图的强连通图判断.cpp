#include<bits/stdc++.h>
using namespace std;

const int Max_n = 110;

int g[Max_n][Max_n],n,m;

void CreatEdge(int a,int b){
	g[a][b] = 1;
}

//深度优先搜索寻找是否存在start到to的路径 
bool dfs(int start,int to){
	int st[Max_n] = {0};
	vector<int> ans;
	stack<int> s;
	s.push(start);
	while(!s.empty()){
		int temp = s.top();
		s.pop();
		if(temp == to) return true;
		if(st[temp]) continue;
		st[temp] = 1;
		for(int i = n - 1;i >= 0;i--){
			if(g[temp][i]) s.push(i);
		}
	}
	return false;
}

//判断是否为强连通图 
bool IsStrongly(){
	for(int i = 0;i < n - 1;i++){ //枚举起点
		for(int j = i + 1;j < n;j++){//枚举终点
			if(!dfs(i,j)) return false;
		}
	}
	return true;
}

int main(){
	cin >> n >> m;
	int a,b;
	for(int i = 0;i < m;i++){
		cin >> a >> b;
		CreatEdge(a,b);
	}
	if(IsStrongly()) cout << "此图为强连通图.\n";
	else cout << "此图为不是强连通图.\n";
	return 0;
}

/*
case 1:
7 9
0 1
3 0
4 2
1 4
5 1
5 3
1 6
6 2
4 5

case 2:
7 10
0 1
2 0
3 0
4 2
1 4
5 1
5 3
1 6
6 2
4 5
*/