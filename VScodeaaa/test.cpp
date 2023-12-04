#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e6 + 10;
	
vector<int> tmp(N,0);
void Merge(vector<int>& nums,int left,int mid,int right){
	int i = left,j = mid + 1,k = 0;
	while(i <= mid && j <= right){
		if(nums[i] > nums[j]){
			tmp[k] = nums[j];
			j++;
		}
		else{
			tmp[k] = nums[i];
			i++;
		}
		k++;
	}
	for(;i <= mid;k++,i++) tmp[k] = nums[i];
	for(;j <= right;j++,k++) tmp[k] = nums[j];
	k = 0;
	for(i = left;i <= right;i++,k++) nums[i] = tmp[k];
}

void MergeSort(vector<int> &nums,int left,int right){
	if(right - left < 1) return;
	int mid = (left + right) / 2;
	MergeSort(nums,left,mid);
	MergeSort(nums,mid + 1,right);
	Merge(nums,left,mid,right);
}

int main() {
	vector<int> nums;
	int n;
	cout << "请输入待排序列长度:\n";
	cin >> n;
	cout << "请输入待排序序列:\n";
	while(n--){
		int t;
		cin >> t;
		nums.push_back(t);
	}
	MergeSort(nums,0,nums.size() - 1);
	cout << "归并排序结果为:\n"; 
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << "\n";
	return 0;
}

/*
13
31 47 87 28 43 34 89 45 66 93 30 19 51
17
74 11 16 70 63 59 31 39 42 88 27 5 66 36 95 42 32
19
93 58 0 80 12 9 57 95 13 84 28 56 6 28 42 14 97 70 21
*/

