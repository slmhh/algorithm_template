#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int nums[N],size = 0;
vector<int> ans;
int n;

int main(){
    cout << "请输入要生成虚了数量:\n";
    cin >> n;
	srand(time(0));
	ifstream fin;
	ofstream fout;
	fout.open("排序样例.txt",ios::out);
	while(size < n){
		int t = rand() % n;
		if(nums[t] == 0){
			nums[t]++;
			ans.push_back(t);
			size++;
		}
	}
	for(int i = 1;i <= n;i++){
		fout << ans[i - 1] << " ";
		if(i % 10 == 0) fout << "\n";
	}
	fout.close();
	cout << "生成完毕.\n" ;
    return 0;
}