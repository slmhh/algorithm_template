#include<bits/stdc++.h>
using namespace std;

string g[55];
int n,m;
int movex[4] = {0,0,1,-1},movey[4] = {1,-1,0,0};
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        //cout << temp.first << " " << temp.second << "\n";
        for(int i = 0;i < 4;i++){
            if(temp.first + movex[i] >= 0 && temp.first + movex[i] < n && temp.second + movey[i] >= 0 && temp.second + movey[i] < m)
                if(g[temp.first + movex[i]][temp.second + movey[i]] == '1'){
                    g[temp.first + movex[i]][temp.second + movey[i]] = '0';
                    q.push({temp.first + movex[i],temp.second + movey[i]});
                }
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int ans = 0;
        cin >> n >> m;
        for(int i = 0;i < n;i++){
            cin >> g[i];
        }
        for(int i = 0;i <  n;i++){
            for(int j = 0;j < m;j++){
                if(g[i][j] == '1'){
                    bfs(i,j);
                    ans++;
                }
            }
        }  
        cout << ans << "\n";
    }
    return 0;
}