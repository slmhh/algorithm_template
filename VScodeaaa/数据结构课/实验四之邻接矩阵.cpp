/*
无向图
#include<bits/stdc++.h>
using namespace std;

const int Max_n = 110;

int g[Max_n][Max_n],n,m;
char p[Max_n];

//a为起点，b为终点
void CreatEdge(int a,int b){
	g[a][b] = 1;
}

void dfs(int start){
	int st[Max_n] = {0};
	stack<int> s;
	s.push(start);
	cout << "从" << start << "开始的深度优先搜索为:\n";
	while(!s.empty()){
		int temp = s.top();
		s.pop();
		if(st[temp]) continue;
		st[temp] = 1;
		cout << p[temp] << " ";
		for(int i = n - 1;i >= 0;i--){
			if(g[temp][i]) s.push(i);
		}
	}
	cout << "\n";
}

void bfs(int start){
	int st[Max_n] = {0};
	queue<int> q;
	q.push(start);
	cout << "从" << start << "开始的广度优先搜索为:\n";
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		if(st[temp]) continue;
		st[temp] = 1;
		cout << p[temp] << " ";
		for(int i = 0;i < n;i++){
			if(g[temp][i]) q.push(i);
		}
	}
	cout << "\n";
}

int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++) 
		cin >> p[i];
	int a,b;
	for(int i = 0;i < m;i++){
		cin >> a >> b;
		CreatEdge(a,b);
		CreatEdge(b,a);
	}
	int t;
	cin >> t;
	dfs(t);
	bfs(t);
	return 0;
}

/*
case 1:
7 8
A
B
C
D
E
F
G
0 1
0 4
1 3
1 2
2 3
2 6
2 4
4 5
0
*/

//有向图
#include<bits/stdc++.h>
using namespace std;

const int Max_n = 110;

int g[Max_n][Max_n],n,m;

//a为起点，b为终点
void CreatEdge(int a,int b){
	g[a][b] = 1;
}

//深度优先搜索
void dfs(int start){
	int st[Max_n] = {0};
	stack<int> s;
	s.push(start);
	cout << "从" << start << "开始的深度优先搜索为:\n";
	while(!s.empty()){
		int temp = s.top();
		s.pop();
		if(st[temp]) continue;
		st[temp] = 1;
		cout << p[temp] << " ";
		for(int i = n - 1;i >= 0;i--){
			if(g[temp][i]) s.push(i);
		}
	}
	cout << "\n";
}

//广度优先搜索
void bfs(int start){
	int st[Max_n] = {0};
	queue<int> q;
	q.push(start);
	cout << "从" << start << "开始的广度优先搜索为:\n";
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		if(st[temp]) continue;
		st[temp] = 1;
		cout << p[temp] << " ";
		for(int i = 0;i < n;i++){
			if(g[temp][i]) q.push(i);
		}
	}
	cout << "\n";
}

int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++) 
		cin >> p[i];
	int a,b;
	for(int i = 0;i < m;i++){
		cin >> a >> b;
		CreatEdge(a,b);
		CreatEdge(b,a);
	}
	int t;
	cout << "请输入遍历起点:\n"; 
	cin >> t;
	dfs(t);
	bfs(t);
	return 0;
}