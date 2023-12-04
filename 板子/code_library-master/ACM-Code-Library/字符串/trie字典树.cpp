#include<iostream>
using namespace std;
const int N = 100010;

int son[N][26],cnt[N] = {0},idx = 0;
char str[N];

void insert(char str[]){  //插入 
    int p = 0;
    for(int i = 0;str[i];i++){
        int a = str[i] - 'a';
        if(!son[p][a]) son[p][a] = ++idx;  //如果此处字母不存在就创建一个 
        //cnt[p]++;
        p = son[p][a];  //指向下一个位置 
    }
    cnt[p]++;  //该处单词数+1 
}

int find(char str[]){  //找 
    int p = 0;
    for(int i = 0;str[i];i++){
        int a = str[i] - 'a';
        if(!son[p][a]) return 0; //没找到 
        p = son[p][a];
    }
    return cnt[p];
}

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> str;
		insert(str);
	}
	cin >> str;
	if(find(str) != 0){
		cout << find(str) << endl;
	}
	else cout << -1;
	return 0;
}
