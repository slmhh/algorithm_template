#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
struct plane{
    int D;
    int T;
    int L;
};
vector<plane> nums;
vector<int> st;
bool flag = false;
bool dfs(int deep,int lasttime){
    if(flag) return true;
    if(deep >= n){
        flag = true;
        return true;
    }
    for(int i = 0;i < n;i++){
        //可以降落
        if(!st[i] && nums[i].T + nums[i].D >= lasttime){
            st[i] = true;
            //记得取max
            if(dfs(deep + 1,max(lasttime,nums[i].T) + nums[i].L)){
                flag = true;
                return true;
            }
            st[i] = false;
        }
        else if(!st[i] && nums[i].T + nums[i].D < lasttime){
            return false;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        flag = false;
        st.resize(n);
        for(int i = 0;i < n;i++){
            plane a;
            cin >> a.T >> a.D >> a.L;
            nums.push_back(a);
        }
        if(dfs(0,0)) cout << "YES\n";
        else cout << "NO\n";
        nums.clear();
        st.clear();
    }
    return 0;
}