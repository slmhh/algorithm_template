#include<bits/stdc++.h>
using namespace std;

const int Max_n = 110;

int n, m;
struct vertex {
	vertex* next;
	int idx;
};
vertex head[Max_n];

//a为起点，b为终点
void CreatEdge(int a, int b) {
	vertex* temp = new vertex;
	temp->idx = b;
	temp->next = head[a].next;
	head[a].next = temp;
}

//深度优先搜索
void dfs(int start) {
	int st[Max_n] = { 0 };
	stack<int> s;
	s.push(start);
	cout << "从" << start << "开始的深度优先搜索为:\n";
	while (!s.empty()) {
		int temp = s.top();
		s.pop();
		if (st[temp]) continue;
		st[temp] = 1;
		cout << temp << " ";
		vertex* t = head[temp].next;
		while(t != NULL){
			s.push(t->idx);
			t = t->next;
		}
	}
	cout << "\n";
}

//广度优先搜索
void bfs(int start) {
	int st[Max_n] = { 0 };
	queue<int> q;
	q.push(start);
	cout << "从" << start << "开始的广度优先搜索为:\n";
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (st[temp]) continue;
		st[temp] = 1;
		cout << temp << " ";
		vertex* t = &head[temp];
		while (t != NULL) {
			q.push(t->idx);
			t = t->next;
		}
	}
	cout << "\n";
}

//初始化
void init() {
	for (int i = 0; i < n; i++) {
		head[i].idx = i;
		head[i].next = NULL;
	}
}

int main() {
	cin >> n >> m;
	init();
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		CreatEdge(a, b);
	}
	int t;
	cout << "请输入遍历起点:\n"; 
	cin >> t;
	dfs(t);
	bfs(t);
	return 0;
}

/*
case 1:
7 8
0 1
0 4
1 3
1 2
2 3
2 6
2 4
4 5
0

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
0
*/