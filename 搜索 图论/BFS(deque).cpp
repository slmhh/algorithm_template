#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 110;

struct Dot {
    int x;
    int y;
    int step;
};


int m, n;
string ma[N];  //地图 
int mx[4] = { 0,1,0,-1 }, my[4] = { -1,0,1,0 };  //移动 
int walk[N][N] = {0};  //走过的路 

int bfs() {
    queue<Dot> q;
    Dot temp;
    temp.x = 0;
    temp.y = 0;
    temp.step = 0;
    walk[0][0] = 1;
    q.push(temp);  //设置起点 

    while (!q.empty()) {
        temp = q.front();
        q.pop();   //取出队首坐标

        if (temp.x == m - 1 && temp.y == n - 1) return temp.step; //是终点就返回 


        for (int i = 0; i < 4; i++) {
            Dot nd;
            nd.x = temp.x + mx[i];
            nd.y = temp.y + my[i]; //移动
            //      x是否越界                  y是否越界                此处是否能走            此处是否走过 
            if (nd.x >= 0 && nd.x < m && nd.y >= 0 && nd.y < n && ma[nd.x][nd.y] == '.' && walk[nd.x][nd.y] == 0) {
                walk[nd.x][nd.y] = 1;   //标记为走过 
                nd.step = temp.step + 1;  //比前一个点远1 
                q.push(nd);
            }
        }

    }
    return -1;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> ma[i];
    }
    if (bfs() != -1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
