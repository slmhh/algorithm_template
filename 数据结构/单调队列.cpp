#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

const int N = 1e6 + 10;
deque<long long int> Q;//储存的是编号 
long long int a[N];
long long int n,k;

//求最大构建递减的单调队列 
void cmax(){
	//创建初始的窗口(到k - 1) 
	for(int i = 0;i < k - 1;i++){
		//队列不为空，且队尾元素比a[i]小，则弹出队尾元素 
		while(!Q.empty() && a[i] >= a[Q.back()]) Q.pop_back(); 
		Q.push_back(i);
	}
	
	for(int i = k - 1;i < n;i++){
		//队列不为空，且队尾元素比a[i]小，则弹出队尾元素 
		while(!Q.empty() && a[i] >= a[Q.back()]) Q.pop_back();
		Q.push_back(i);
		//窗口滑过了队头元素，则弹出队尾元素 
		while(!Q.empty() && Q.front() <= i - k) Q.pop_front();
		printf("%lld ",a[Q.front()]);
	}
	printf("\n");
}

//求最小构建递增的单调队列
void cmin(){
	//创建初始的窗口(到k - 1) 
	for(int i = 0;i < k - 1;i++){
		while(!Q.empty() && a[i] <= a[Q.back()]) Q.pop_back();
		Q.push_back(i);
	}
	
	for(int i = k - 1;i < n;i++){
		while(!Q.empty() && a[i] <= a[Q.back()]) Q.pop_back();
		Q.push_back(i);
		while(!Q.empty() && Q.front() <= i - k) Q.pop_front();
		printf("%lld ",a[Q.front()]);
	}
	printf("\n");
}

int main(){
	cin >> n >> k;
	for(int i = 0;i < n;i++) cin >> a[i];
	cmin();
	Q.clear();
	cmax();
	return 0;
}
