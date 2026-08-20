#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 3e6 + 10;

// in:入度
ll in[110],g[110][110],n;
vector<ll> ans;

void toposort(){
	queue<ll> q;
	for(int i = 1;i <= n;i++){  //找到入度为0的节点 
		if(in[i] == 0) q.push(i);
	}
	while(!q.empty()){
		ll temp = q.front();
		q.pop();
		ans.push_back(temp);
		for(int i = 1;i <= n;i++){
			if(g[temp][i]){
				if(in[i] == 1) //入度归零 
					q.push(i);
				in[i]--;
			}
		}
	}
	for(int i = 0;i < ans.size();i++) cout << ans[i] << " ";
	cout << "\n"; 
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		ll t;
		cin >> t;
		while(t != 0){
			g[i][t] = 1;
			in[t]++;
			cin >> t;
		}
	}
	toposort();
	return 0;
}

/*#include<stdio.h>
#include<map>
#include<queue>
#include<string.h>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int h[N],e[N],ne[N],idx;
int d[N];//入度 
int ans[N],top;*/

/*思路
1. 看这个图是否有环，如果没有环就一定存在拓扑序列
2. 求出每个点的入度
3. 把所有入度为 0 的点入队
4. 枚举每一条边，删除它就是让 d[j] --;
5. 当入度为 0 时，说明前面的点都已经有序，将当前点入队
6. 当所有点都入队时说明存在拓扑序列
*/ 

/*void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
} 

void topsort(){
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(!d[i]){
			q.push(i);
			ans[++top] = i;
		}
	}
	while(q.size()){
		int t = q.front();
		q.pop();
		for(int i = h[t]; ~i;i = ne[i]){
			int j = e[i];
			if(--d[j] == 0){
				q.push(j);
				ans[++top] = j;
			}
		}
	}	
}

int main(){
	memset(h,-1,sizeof(h));
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		d[b]++;
	}
	topsort();
	if(top != n) puts("-1");
	else{
		for(int i = 1;i <= n;i++){
			printf("%d ",ans[i]);
		}	
	}
	return 0;
}*/

/*
3 3
1 2
2 3
1 3

1 2 3*/

