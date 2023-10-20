#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//排序
int main(){
    ll n,t;
    cin >> n;
    vector<ll> nums;
    while(n--){
        cin >> t;
        nums.push_back(t);
    }
    sort(nums.begin(),nums.end());
    nums.push_back(-1);
    ll ans = nums[0],max_c = 0;
    for(int i = 0;i < nums.size() -1 ;i++){
        ll cnt = 1;
        while(nums[i + 1] == nums[i]){
            cnt++;
            i++;
        }
        if(cnt > max_c){
            max_c = cnt;
            ans = nums[i];
        }
    }
    cout << ans << "\n";
    return 0;
}


//桶
/*ll cnt[10010] = {0};

int main(){
    ll n,t;
    cin >> n;
    while(n--){
        cin >> t;
        cnt[t]++;
    }
    ll min_n = 0,max_cnt = 0; 
    for(int i = 1;i <= 10000;i++){
        if(cnt[i] > max_cnt){
            max_cnt = cnt[i];
            min_n = i;
        }
    }
    cout << min_n << "\n";
    return 0;
}*/