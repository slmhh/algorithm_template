#include<stdio.h>

void QuickSort(int *nums, const int left, const int right) {
	if (left > right) { return; }
	int temp,i,j,temp2;
	temp = nums[left];
	i = left;
	j = right;
	while (i != j) {
		while (nums[j] >= temp && i < j) {     //要先往前找，再往后找(记得是>=)
			j--;
		}
		while (nums[i] <= temp && i < j) {
			i++;
		}
		if (i < j) {
			temp2 = nums[i];
			nums[i] = nums[j];
			nums[j] = temp2;
		}
	}
	nums[left] = nums[i];
	nums[i] = temp;
/*	
	for(int k = 0;k < 10;k++) printf("%d ",nums[k]);
	printf("\n");
*/
	QuickSort(nums, left, i - 1);
	QuickSort(nums,i + 1, right);
}

int main() {
	int nums[10] = { 10,18,4,3,6,12,1,9,18,8 };
	QuickSort(nums,0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d ",nums[i]);
	}
	printf("\n");
	return 0;
}
