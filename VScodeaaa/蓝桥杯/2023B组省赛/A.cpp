#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int nums[110];

int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int m,int d){
    if(d <= month[m - 1]) return true;
    return false;
}

bool find(int y,int m,int d){
    vector<int> data;
    if(d < 10){
        data.push_back(d);
        data.push_back(0);
    }
    else{
        data.push_back(d % 10);
        data.push_back(d / 10);
    }
    if(m < 10){
        data.push_back(m);
        data.push_back(0);
    }
    else{
        data.push_back(m % 10);
        data.push_back(m / 10);
    }
    while(y > 0){
        data.push_back(y % 10);
        y /= 10;
    }
    reverse(data.begin(),data.end());
    int idx = 0;
    for(int i = 0;i < 100 && idx < 8;i++){
        if(nums[i] == data[idx]) idx++;
    }
    if(idx == 8) return true;
	return false;
}

int main(){
    for(int i = 0;i < 100;i++) cin >> nums[i];
    int ans = 0;
    for(int i = 1;i <= 12;i++){
        for(int j = 1;j <= 31;j++){
            if(check(i,j) && find(2023,i,j)){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}

/*235*/