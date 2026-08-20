#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

//牛客小白月赛75 C 
int main(){
    int n;
    cin >> n;
    vector<string> good,bad;
    int t = 3;
    while(t--){
        good.push_back("******");
        bad.push_back("......");
    }
    t = 3;
    while(t--){
        good.push_back("***...");
        bad.push_back("...***");
    }
    
    for(int i = 2;i <= n;i++){
        vector<string> tg,tb;
        
        //生成i级豆子
        for(int j = 0;j < good.size();j++){
            tg.push_back(bad[j] + bad[j]);
            tb.push_back(good[j] + good[j]);
        }
        
        for(int j = 0;j < good.size();j++){
            tg.push_back(bad[j] + good[j]);
            tb.push_back(good[j] + bad[j]);
        }
        
        good = tg;
        bad = tb;
    }
    for(int i = 0;i < good.size();i++) cout << good[i] << endl;
    return 0;
}
