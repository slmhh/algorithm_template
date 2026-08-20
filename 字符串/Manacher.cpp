#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 5e6 + 10;

//奇偶归一化处理
string change(string str){
    string temp = "!#";
    for(int i = 0;i < str.size();i++){
        temp += str[i];
        temp += '#';
    }
    return temp;
}

int Manacher(string str){
    if(str.size() == 0 || str.size() == 1)
        return str.size();
    int maxright = 0,mid = 0,ans = 0;
    str = change(str);
    vector<int> p(str.size());
    for(int i = 1;i < str.size();i++){
        //对称
        if(i < maxright) p[i] = min(p[2 * mid - i],maxright - i + 1);
        else p[i] = 1 + (str[i] != '#');
        //扩展
        while(i - p[i] >= 0 && p[i] + i < str.size() && str[i - p[i]] == str[i + p[i]]){
            p[i]++;
        }
        //变更最右回文子串
        if(i + p[i] - 1 > maxright){
            mid = i;
            maxright = i + p[i] - 1;
        }
        ans = max(ans,p[i] - 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string str;
    cin >> str;
    cout << Manacher(str) << "\n";
    return 0;
}
