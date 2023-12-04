#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int *nums,int len){
	for(int i = 0;i < len - 1;i++){
		for(int j = len - 1;j > i;j--){
			if(nums[j] < nums[j - 1]){
				int temp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = temp;
			}
		}
	}
}

int nums[1000000],n = 10000;

int main() {
	//int nums[10] = { 5,6,7,1,4,0,9,8,3,2};
	
	ifstream fin;
	ofstream fout;
	fin.open("排序样例.txt",ios::in);
	for(int i = 0;i < n;i++){
		fin >> nums[i];
	}
	
	clock_t t1,t2;
	t1 = clock();
	BubbleSort(nums,n);
	t2 = clock();
	printf("冒泡排序结果为:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ",nums[i]);
	}
	printf("\n");
	printf("用时:%.10lf",double(t2 - t1) / CLOCKS_PER_SEC);
	return 0;
}
