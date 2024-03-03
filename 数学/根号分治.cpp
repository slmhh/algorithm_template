#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 150000 + 10,M = 1500 + 10;

//P3396 哈希冲突
ll nums[N],ans[M][M];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m,x,y,Size;
    string op;
    cin >> n >> m;
    Size = (ll)sqrt(n);
    for(int i = 1;i <= n;i++) cin >> nums[i];
    //预处理小于sqrt(n)的答案
    for(int i = 1;i <= Size;i++)  //枚举p
        for(int j = 1;j <= n;j++)  //枚举k 
            ans[i][j % i] += nums[j];

    while(m--){
        cin >> op >> x >> y;
        if(op[0] == 'A'){
            if(x <= Size) cout << ans[x][y] << "\n";
            else{
                ll sum = 0;
                for(int i = y;i <= n;i += x) sum += nums[i];
                cout << sum << "\n";
            }
        }
        else{
            //更新
            for(int i = 1;i <= Size;i++)
                ans[i][x % i] += y - nums[x];
            nums[x] = y;
        }
    }
    return 0;
}
