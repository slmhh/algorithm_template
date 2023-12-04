#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &nums){
	for(int i = 0;i < nums.size() - 1;i++){
		for(int j = nums.size() - 1;j > i;j--){
			if(nums[j] < nums[j - 1]){
				int temp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = temp;
			}
		}
	}
}

void InsertionSort(vector<int> &nums){
	for(int i = 1;i < nums.size();i++){
		int temp = nums[i],j = i - 1;
		while(j >= 0 && nums[j] > temp){
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = temp;
	}
}

void HeapSort(vector<int> &nums){
	priority_queue<int,vector<int>,greater<int> > heap;
	for(int i = 0;i < nums.size();i++){
		heap.push(nums[i]);
	}
	for(int i = 0;i < nums.size();i++){
		nums[i] = heap.top();
		heap.pop();
	}
}

void MergeSort(vector<int> &nums,int left,int right){
	if(right - left <= 1) return;
	int mid = left + ((right - left) >> 1);
	MergeSort(nums,left,mid),MergeSort(nums,mid,right);
	vector<int> tmp(nums.size());
	merge(nums.begin() + left,nums.begin() + mid,nums.begin() + mid,nums.begin() + right,tmp.begin() + left);
	for(int i = left;i < right;i++) nums[i] = tmp[i];
}

void QuickSort(vector<int> &nums, const int left, const int right) {
	if (left > right) { return; }
	int temp,i,j,temp2;
	temp = nums[left];
	i = left;
	j = right;
	while (i != j) {
		while (nums[j] >= temp && i < j)  j--;
		while (nums[i] <= temp && i < j)  i++; 
		if (i < j) {
			temp2 = nums[i];
			nums[i] = nums[j];
			nums[j] = temp2;
		}
	}
	nums[left] = nums[i];
	nums[i] = temp;
	QuickSort(nums, left, i - 1);
	QuickSort(nums,i + 1, right);
}

void ShellSort(vector<int> &nums){
	int h = 1;
	while(h < nums.size() / 3){
		h = h * 3 + 1;
	}
	while(h >= 1){
		for(int i = h;i < nums.size();i++){
			for(int j = i;j >= h && nums[j] < nums[j - h];j -= h){
				int temp = nums[j];
				nums[j] = nums[j - h];
				nums[j - h] = temp;
			}
		}
		h /= 3;
	}
}

void SelectionSort(vector<int> &nums){
	for(int i = 0;i < nums.size();i++){
		int MinIdx = i;
		for(int j = i;j < nums.size();j++){
			if(nums[j] < nums[MinIdx]) MinIdx = j;
		}
		int temp = nums[i];
		nums[i] = nums[MinIdx];
		nums[MinIdx] = temp;
	} 
}

vector<int> nums,test;

void InitTest(){
	test.clear();
	for(int i = 0;i < nums.size();i++){
		test.push_back(nums[i]);
	}
}

int main() {
	//int nums[10] = { 5,6,7,1,4,0,9,8,3,2};
	
	ifstream fin;
	ofstream fout;
	fin.open("排序样例.txt",ios::in);
	int t;
	for(int i = 0;i < 10000;i++){
		fin >> t;
		nums.push_back(t);
	}
	
	InitTest();
	clock_t t1,t2;
	t1 = clock();
	BubbleSort(test);
	t2 = clock();
	printf("冒泡排序用时:%.10lf\n",double(t2 - t1) / CLOCKS_PER_SEC);
	
	InitTest();
	t1 = clock();
	InsertionSort(test);
	t2 = clock();
	printf("插入排序用时:%.10lf\n",double(t2 - t1) / CLOCKS_PER_SEC);
	
	InitTest();
	t1 = clock();
	HeapSort(test);
	t2 = clock();
	printf("堆排序用时  :%.10lf\n",double(t2 - t1) / CLOCKS_PER_SEC);
	
	InitTest();
	t1 = clock();
	MergeSort(test,0,test.size()); 
	t2 = clock();
	printf("归并排序用时:%.10lf\n",double(t2 - t1) / CLOCKS_PER_SEC);
	
	InitTest();
	t1 = clock();
	QuickSort(test,0,test.size());
	t2 = clock();
	printf("快速排序用时:%.10lf\n",double(t2 - t1) / CLOCKS_PER_SEC);
	
	InitTest();
	t1 = clock();
	SelectionSort(test); 
	t2 = clock();
	printf("选择排序用时:%.10lf\n",double(t2 - t1) / CLOCKS_PER_SEC);
	
	InitTest();
	t1 = clock();
	ShellSort(test);
	t2 = clock();
	printf("希尔排序用时:%.10lf\n",double(t2 - t1) / CLOCKS_PER_SEC);
	
	return 0;
}