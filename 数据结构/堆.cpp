#include<bits/stdc++.h>
#define debug(x) cout << "#x" << x << endl;
#define all(x) (x).begin(),(x).end()
using namespace std;

int heap[100],sz = 0;
int nums[10] = {0,1,9,8,6,7,3,4,2,5};
//小根堆 
void push(int x){
	//自己的节点编号 
	int i = sz++;
	//如果已经没有大小颠倒就退出 
	while(i > 0){
		//父亲节点的编号 
		int p = (i - 1) / 2;
		//如果已经没有大小颠倒就退出
		if(heap[p] <= x) break;
		//把父亲节点的数组放下来,而把自己提上去 
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
}

int pop(){
	//最小值
	int ret = heap[0];
	//要提到根的数值
	int x = heap[--sz];
	//从根开始向下交换
	int i = 0;
	while(i * 2 + 1 < sz){
		//比较儿子的值
		int a = i * 2 + 1,b = i * 2 + 2;
		if(b < sz && heap[b] < heap[a]) a = b;
		//如果已经没有大小颠倒就退出
		if(heap[a] >= x) break;
		//把儿子的数值提上来
		heap[i] = heap[a];
		i = a; 
	}
	heap[i] = x;
	return ret;
}

int main(){
    for(int i = 0;i < 10;i++){
    	push(nums[i]);
	}
    while(sz != 0){
    	printf("%d ",pop());
	}
    return 0;
}
