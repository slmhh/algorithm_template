#include<bits/stdc++.h>
using namespace std;

void SeqSearch(vector<int> &nums,int n){
	for(int i = 0;i < nums.size();i++){
		if(nums[i] == n){
			cout << "数值" << n << "的下标为" << i << "\n";
			return;
		}
	}
	cout << "没有找到" << n << "\n";
}

void BinarySeatch(vector<int> &nums,int n){
	int l = 0,r = nums.size() - 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(nums[mid] == n){
			cout << "数值" << n << "的下标为" << mid << "\n";
			return;
		}
		else if(nums[mid] > n) r = mid - 1;
		else l = mid + 1;
	}
	cout << "没有找到" << n << "\n";
}

int main(){
	cout << "输入要查找的序列长度:\n";
	int len,t;
	cin >> len;
	vector<int> nums(len);
	cout << "输入要查找的序列:\n";
	for(int i = 0;i < len;i++){
		cin >> nums[i];
	}
	cout << "请输入查找的值:\n";
	cin >> t;
	cout << "顺序查找结果为:\n"; 
	SeqSearch(nums,t);
	cout << "折半查找结果为:\n";
	BinarySeatch(nums,t);
	return 0;
}

/*
10
2 3 5 7 11 13 17 19 23 29
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