#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll nums[N];
    ll n,cnt = 0;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> nums[i];
    for(int i = 1;i < n - 1;i++)
        if((nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) || (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]))
            cnt++;
    cout << cnt << "\n";
    return 0;
}