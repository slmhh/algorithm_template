#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,x1,y1,x2,y2,cnt = 0;
    ll nums[110][110] = {0};
    cin >> n;
    while(n--){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1;i < x2;i++){
            for(int j = y1;j < y2;j++){
                nums[i][j] = 1;
            }
        }
    }
    for(int i = 0;i < 101;i++){
        for(int j = 0;j < 101;j++){
            if(nums[i][j] != 0) cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}