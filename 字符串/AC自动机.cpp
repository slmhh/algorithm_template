#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10,mod = 998244353;

struct ACAM{
    vector<int> ne,in,cnt,f;
    vector<vector<int>> son;
    int idx = 0;
    ACAM(){
        son.resize(N,vector<int>(26,0));
        ne.resize(N,0),in.resize(N,0);
        cnt.resize(N,0),f.resize(N,0);
    }
    ll insert(string str){  //插入模式串
        int p = 0;
        for(int i = 0;str[i];i++){
            int a = str[i] - 'a';
            if(!son[p][a]) son[p][a] = ++idx;  //如果此处字母不存在就创建一个 
            p = son[p][a];  //指向下一个位置 
        }
        cnt[p]++;  //该处单词数+1 
        return p;
    }

    void build(){
        queue<int> q;
        for(int i = 0;i < 26;i++)
            if(son[0][i]) q.push(son[0][i]);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i = 0;i < 26;i++){
                int v = son[u][i];
                if(v){
                    ne[v] = son[ne[u]][i];  //建立回跳边
                    q.push(v);
                    in[son[ne[u]][i]]++;
                }
                else son[u][i] = son[ne[u]][i];  //建转移边
            }
        }
    }
    void query(string str,int n){
        for(int k = 0,i = 0;k < str.size();k++){
            i = son[i][str[k] - 'a'];
            f[i]++;
            // for(int j = i;j && ~cnt[j];j = ne[j]){
            //     ans += cnt[j];
            //     cnt[j] = -1;//不重复计数
            // }
        }
        queue<ll> q;
        for(int i = 1;i <= idx;i++)
            if(in[i] == 0) q.push(i);
        while(!q.empty()){
            ll u = q.front(),v = ne[u];
            q.pop();
            f[v] += f[u],in[v]--;
            if(v != 0 && in[v] == 0) q.push(v);
            f[u] *= cnt[u];
        }
    }
};

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n;
    string t,temp;
    cin >> temp >> n;
    ACAM ac;
    map<string,ll> mp;
    vector<string> str(n + 1); 
    for(int i = 1;i <= n;i++){
        cin >> t;
        str[i] = t;
        if(!mp[t])mp[t] = ac.insert(t);
    }
    ac.build();
    ac.query(temp,n);
    for(int i = 1;i <= n;i++){
        cout << ac.f[mp[str[i]]] << "\n";
    }
    return 0;
}
