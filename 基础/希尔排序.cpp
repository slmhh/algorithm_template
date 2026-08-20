#include<stdio.h>

void ShellSort(int *nums,int len){
	int h = 1;
	while(h < len / 3){
		h = h * 3 + 1;
	}
	while(h >= 1){
		for(int i = h;i < len;i++){
			for(int j = i;j >= h && nums[j] < nums[j - h];j -= h){
				int temp = nums[j];
				nums[j] = nums[j - h];
				nums[j - h] = temp;
			}
		}
		h /= 3;
	}
}

int main() {
	int nums[10] = { 5,6,7,1,4,0,9,8,3,2};
	ShellSort(nums,10);
	for (int i = 0; i < 10; i++) {
		printf("%d ",nums[i]);
	}
	printf("\n");
	return 0;
}
