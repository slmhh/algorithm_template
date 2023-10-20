#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    string str = "",temp;
    map<string,int> m;
    for(int i = 0;i < n;i++){
        str = "";
        for(int j = 0;j < 8;j++){
            cin >> temp;
            str = str + temp;
        }
        m[str]++;
        cout << m[str] << "\n";
    }
    return 0;
}