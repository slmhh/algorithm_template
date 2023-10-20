#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
using namespace std;


//‘≠Ã‚  [ABC271C] Manga
const int N = 3e5 + 10;
map<int,bool> nums;
deque<long long int> a;
int main(){
	long long int n,cnt = 0,x,sale = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		scanf("%lld",&x);
		if(!nums.count(x)){
			nums.insert(pair<int,bool>(x,true));
			a.push_back(x);
			continue;
		}
		sale++;
	}
	sort(a.begin(),a.end());
	
	for(int i = 0;!a.empty() || sale >= 2;i++){
		if(a.front() == i + 1){
			cnt++;
			a.pop_front();
		}
		else{
			while(sale < 2 && !a.empty()){
				a.pop_back();
				sale++;
			}
			if(sale >= 2){
				sale -= 2;
				cnt++;
				continue;
			}
			else{
				break;
			}
		}
	}
	cout << cnt <<endl;
	return 0;
	}
