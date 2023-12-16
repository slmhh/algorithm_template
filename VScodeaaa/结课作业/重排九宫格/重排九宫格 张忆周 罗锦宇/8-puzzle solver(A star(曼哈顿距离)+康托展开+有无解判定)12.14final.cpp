#include<iostream>
#include<vector>
#include<ctime>
#include<iomanip>
#include<algorithm>
using namespace std;

int n = 3;  //阶数
string dir[4] = { "right","left","up","down" }; //移动方向
vector<vector<int>> target = { {1,2,3},{8,0,4},{7,6,5} };//终态

//计算康托展开
int factorial[10] = { 1,1,2,6,24,120,720,5040,40320,362880 };
int Cantor(vector<vector<int> >& nums) {
	int x = 0, a = 0;
	vector<int> A;
	for (int i = 0; i < n * n; i++) {
		a = 0;
		for (int j = i + 1; j < n * n; j++)
			if (nums[j / n][j % n] < nums[i / n][i % n]) a++;
		A.push_back(a);
	}


	for (int i = 0; i < n * n; i++)
		x += A[i] * factorial[n * n - i - 1];
	return x;
}

//优先队列(小根堆) 
template<typename T>
class PriorityQueue {
public:
	vector<T> Heap;
	int size;
	PriorityQueue() { size = 0; };
	void Push(T x);
	T Top();
	bool Empty() { return size == 0; };
};

//入堆并调整 
template<typename T>
void PriorityQueue<T>::Push(T x) {
	Heap.push_back(x);
	int i = size++;
	while (i > 0) {
		int p = (i - 1) / 2;
		if (Heap[p] <= x) break;
		Heap[i] = Heap[p];
		i = p;
	}
	Heap[i] = x;
}

//取出最小值并调整 
template<typename T>
T PriorityQueue<T>::Top() {
	T temp = Heap[0], x = Heap[--size];
	//从根开始向下交换
	int i = 0;
	while (i * 2 + 1 < size) {
		int t = i * 2 + 1;
		if (t + 1 < size && Heap[t + 1] < Heap[t]) t++;
		//如果已经没有大小颠倒就退出
		if (x <= Heap[t]) break;
		Heap[i] = Heap[t];
		i = t;
	}
	Heap[i] = x;
	return temp;
}

class EightPuzzle {
private:
	vector<vector<int>> S; //九宫格,现态
	string direction;    //移动方向
	int can;       //康托展开值
	int deep;      //搜索深度始态到现态估价函数g(x)
public:
	EightPuzzle() {};
	EightPuzzle(vector<vector<int >>& input);
	void Print();  //输出九宫格 
	void AstarSolve(EightPuzzle& Sg);
	void PrintSolve(EightPuzzle Sg);
	bool Sovleable();
	int h(); //现态到终态估价函数h(x),曼哈顿距离
	friend bool operator < (EightPuzzle a, EightPuzzle b) { return a.deep + a.h() < b.deep + b.h(); }
	friend bool operator <= (EightPuzzle a, EightPuzzle b) { return a.deep + a.h() <= b.deep + b.h(); }
};

int site[9][2] = { {1,1},{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0} };
//利用曼哈顿距离估计 
int EightPuzzle::h() {
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (S[i][j]) res += abs(i - site[S[i][j]][0]) + abs(j - site[S[i][j]][1]);
	return res;
}

//可解的判定(逆序数为奇数可解,反之无解) 
bool EightPuzzle::Sovleable() {
	int inv = 0;
	for (int i = 0; i < n * n; i++)
		for (int j = i + 1; j < n * n; j++)
			if (S[j / n][j % n] && S[i / n][i % n] && S[j / n][j % n] < S[i / n][i % n]) inv++;
	return inv & 1;
}

EightPuzzle::EightPuzzle(vector<vector<int>>& input) {
	S.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			S[i][j] = input[i][j];
	can = Cantor(S);
	deep = 0;
	direction = "start";
}

void EightPuzzle::Print() {
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < S[0].size(); j++) {
			if (S[i][j]) cout << S[i][j] << " ";
			else cout << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int movex[4] = { 0,0,1,-1 }, movey[4] = { 1,-1,0,0 };  //四个方向移动
vector<EightPuzzle> parent(365000); //记录父节点
int st[365000];   //记录是否被搜索过
void EightPuzzle::AstarSolve(EightPuzzle& Sg) {
	if (!Sovleable()) {   //判断有无解
		cout << "此状态无解\n";
		return;
	}
	PriorityQueue<EightPuzzle> q;
	q.Push(*this);
	parent[can] = *this;
	st[can] = 1;
	while (!q.Empty()) {
		EightPuzzle temp = q.Top();
		//判断是否抵达终态
		if (temp.can == Sg.can) {
			Sg = temp;
			PrintSolve(target);
			return;
		}
		vector<vector<int>> ts = temp.S;
		//寻找空格的位置
		int x, y;
		for (int i = 0; i < n * n; i++)
			if (ts[i / n][i % n] == 0) {
				x = i / n;
				y = i % n;
				break;
			}
		//向四个方向交换
		for (int i = 0; i < 4; i++) {
			//判断移动的合法性
			if (x + movex[i] >= 0 && y + movey[i] >= 0 && x + movex[i] < n && y + movey[i] < n) {
				swap(ts[x + movex[i]][y + movey[i]], ts[x][y]);    //移动
				EightPuzzle s(ts);
				swap(ts[x + movex[i]][y + movey[i]], ts[x][y]);    //归位
				//判断是否被检索过并比之前更优 
				if (st[s.can] && st[s.can] <= st[temp.can] + 1) continue;
				st[s.can] = st[temp.can] + 1;
				parent[s.can] = temp;
				s.direction = dir[i];
				s.deep = temp.deep + 1;
				q.Push(s);
			}
		}
	}
}

//打印求解过程 
void EightPuzzle::PrintSolve(EightPuzzle Sg) {
	EightPuzzle temp = Sg;
	vector<EightPuzzle> ans;
	while (temp.can != can) {
		ans.push_back(temp);
		temp = parent[temp.can];
	}
	cout << "最少步解法有" << ans.size() << "步,具体步骤如下:\n";
	ans.push_back(*this);
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << "-----step" << ans.size() - 1 - i << "----\n";
		cout << ans[i].direction << "\n";
		ans[i].Print();
	}
	cout << "finish\n";
}

int main() {
	vector<vector<int>> input(n, vector<int>(n));
	cout << "请输入初始九宫格(用0表示空格):\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> input[i][j];

	EightPuzzle S0(input);
	EightPuzzle Sg(target);
	cout << "初始状态为\n";
	S0.Print();
	cout << "目标状态为\n";
	Sg.Print();
	clock_t start, end;  //计时 
	start = clock();
	S0.AstarSolve(Sg);
	end = clock();
	cout << "用时：" << fixed << setprecision(10) << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
	return 0;
}

//测试用例 
//2 8 3 1 0 4 7 6 5
//题目样例
//1 2 3 8 0 4 7 6 5
//终态 0 
//2 1 3 8 0 4 7 6 5
//无解 

//hack
//7 6 5 4 2 0 3 8 1 
//29
//8 2 1 3 0 4 6 5 7
//20
//2 0 1 5 3 4 7 8 6
//19
