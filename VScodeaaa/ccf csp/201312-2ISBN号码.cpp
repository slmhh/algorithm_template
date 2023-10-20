#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string str;
    cin >> str;
    ll sum = 0;
    for(int i = 0,j = 1;i < str.size() - 2;i++){
        if(str[i] == '-') continue;
        sum += (str[i] - '0') * j;
        j++;
    }
    sum %= 11;
    if(sum == str[12] - '0' || (sum == 10 && str[12] == 'X')){
        cout << "Right\n";
    }
    else{
        if(sum < 10) str[12] = (char)(sum + '0');
        else str[12] = 'X';
        cout << str << "\n";
    }
    return 0;
}