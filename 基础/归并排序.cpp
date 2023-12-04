#include<stdio.h>
#include<algorithm>

void MergeSort(int *nums,int left,int right){
	if(right - left <= 1) return;
	int mid = left + ((right - left) >> 1);
	MergeSort(nums,left,mid),MergeSort(nums,mid,right);
	int tmp[1437] = {0};
	std::merge(nums + left,nums + mid,nums + mid,nums + right,tmp + left);
	for(int i = left;i < right;i++) nums[i] = tmp[i];
}

int main() {
	int nums[10] = { 5,6,7,1,4,0,9,8,3,2};
	MergeSort(nums,0,10);
	for (int i = 0; i < 10; i++) {
		printf("%d ",nums[i]);
	}
	printf("\n");
	return 0;
}
