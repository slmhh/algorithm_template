#include<bits/stdc++.h>
using namespace std;

const int mod = 19;

vector<int> hash;

void init(){
	for(int i = 0;i < mod;i++){
		hash.push_back(0);
	}
}

void insert(int t){
	int key = t % mod;
	while(hash[key] != 0) key++;
	hash[key] = t;
}

bool find(int t){
	int key = t % mod;
	while(hash[key] != 0){
		if(hash[key] == t){
			return true;
		}
		key++;
	}
	return false;
}

int main(){
	init();
	int len,t;
	cout << "输入要查找的序列长度:\n";
	cin >> len;
	cout << "输入要查找的序列:\n";
	for(int i = 0;i < len;i++){
		cin >> t;
		insert(t);
	}
	cout << "请输入查找的值:\n";
	cin >> t;
	if(find(t)){
		cout << "数值" << t << "在序列中存在.\n"; 
	}
	else{
		cout << "数值" << t << "在序列中不存在.\n";
	} 
	return 0;
}

/*
11
3 23 29 7 17 5 19 11 2 13 31
23

10
2 3 5 7 11 13 17 19 23 29
46

20
1 4 9 16 25 36 49 64 81 100 121 169 144 196 225 256 289 324 361 400 
169

20
1 4 9 16 25 36 49 64 81 100 121 169 144 196 225 256 289 324 361 400 
220
*/