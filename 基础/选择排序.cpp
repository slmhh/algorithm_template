#include<stdio.h>

void SelectionSort(int *nums,int len){
	for(int i = 0;i < len;i++){
		int MinIdx = i;
		for(int j = i;j < len;j++){
			if(nums[j] < nums[MinIdx]) MinIdx = j;
		}
		int temp = nums[i];
		nums[i] = nums[MinIdx];
		nums[MinIdx] = temp;
	} 
}

int main() {
	int nums[10] = { 5,6,7,1,4,0,9,8,3,2};
	SelectionSort(nums,10);
	for (int i = 0; i < 10; i++) {
		printf("%d ",nums[i]);
	}
	printf("\n");
	return 0;
}
