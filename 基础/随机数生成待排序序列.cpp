#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+ 10;

int main(){
    cout << "请输入要生成序列数量:\n";
    int n,size = 0;
    cin >> n;
	srand(time(0));
	ifstream fin;
	ofstream fout;
	fout.open("排序样例.txt",ios::out);
	for(int i = 0;i < n;i++){
		int t = rand();
		//fout << t << " ";
		fout << t % 100 << " ";
		size++;
		if(size % 20 == 0) fout << "\n";
	}
	fout.close();
	cout << "生成完毕.\n" ;
    return 0;
}
