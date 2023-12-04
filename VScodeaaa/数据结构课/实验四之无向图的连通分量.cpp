#include<bits/stdc++.h>
using namespace std;

const int Max_n = 110;

int g[Max_n][Max_n],n,m;

void CreatEdge(int a,int b){
	g[a][b] = 1;
	g[b][a] = 1;
}

//深度优先搜索 
vector<int> dfs(int start){
	int st[Max_n] = {0};
	vector<int> ans;
	stack<int> s;
	s.push(start);
	while(!s.empty()){
		int temp = s.top();
		s.pop();
		if(st[temp]) continue;
		st[temp] = 1;
		ans.push_back(temp);
		for(int i = n - 1;i >= 0;i--){
			if(g[temp][i]) s.push(i);
		}
	}
	return ans;
}

//求无向图的连通分量 
void Connected(){
	int cnt = 0,s,st[Max_n] = {0};
	cout << "此图的连通分量为:\n";
	while(cnt < n){
		//遍历寻找未被搜索到的点 
		for(int i = 0;i < n;i++){
			if(st[i] == 0){
				s = i;
				break;
			}
		}
		vector<int> ans = dfs(s);
		cnt += ans.size(); //记录已被遍历点的个数 
		for(int i = 0;i < ans.size();i++){
			cout << ans[i] << " ";
			st[ans[i]] = 1;
		}
		cout << "\n";
	}
}

int main(){
	cin >> n >> m;
	int a,b;
	for(int i = 0;i < m;i++){
		cin >> a >> b;
		CreatEdge(a,b);
	}
	Connected();
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

case 2:
10 9
0 1
0 2
0 3
1 4
2 4
1 5
2 5
6 7
7 8
*/