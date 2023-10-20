#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,t,cnt = 0;
    vector<int> nums;
    cin >> n;
    while(n--){
        cin >> t;
        nums.push_back(t);
    }
    for(int i = 0;i < nums.size();i++){
        for(int j = i + 1;j < nums.size();j++){
            if(abs(nums[i] - nums[j]) == 1) cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}