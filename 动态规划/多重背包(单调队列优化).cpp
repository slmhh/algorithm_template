#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        ll n,V;
        cin >> n >> V;
        vector<ll> f(V + 1),g(V + 1);
        for(int i = 1;i <= n;i++){
            ll c,w,v;
            cin >> v >> w >> c;
            g = f;
            vector<deque<ll>> q(w);
            for(int j = 0;j <= V;j++){
                if(!q[j % w].empty() && (j - q[j % w].front()) / w > c)
                    q[j % w].pop_front();
                
                if(!q[j % w].empty()) f[j] = max(f[j],g[q[j % w].front()] + (j - q[j % w].front()) / w * v);

                while(!q[j % w].empty() && g[j] >= g[q[j % w].back()] + (j - q[j % w].back()) / w * v)
                    q[j % w].pop_back();
                q[j % w].push_back(j);
            }
        }
        cout << *max_element(f.begin(),f.end());
    }
    return 0;
}

