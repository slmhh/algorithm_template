#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int dp[15] = {0};
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,t,ans = 0;
    cin >> n;
    string str;
    for(int i = 0;i < n;i++){
        cin >> str;
        int f = str[0] - '0' ,l = str[str.size() - 1] - '0';
        dp[l] = max(dp[l],dp[f] + 1);
        ans = max(ans,dp[l]);
    }
    cout << n - ans << "\n";
    return 0;
}