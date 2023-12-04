#include<stdio.h>

void InsertionSort(int *nums,int len){
	for(int i = 1;i < len;i++){
		int temp = nums[i],j = i - 1;
		while(j >= 0 && nums[j] > temp){
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = temp;
	}
}

int main() {
	int nums[10] = { 5,6,7,1,4,0,9,8,3,2};
	InsertionSort(nums,10);
	for (int i = 0; i < 10; i++) {
		printf("%d ",nums[i]);
	}
	printf("\n");
	return 0;
}
