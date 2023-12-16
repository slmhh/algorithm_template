#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int n = 3;
//计算康托展开
int factorial[10] = { 1,1,2,6,24,120,720,5040,40320,362880 };

void swap(int* a, int* b) {
	int* c = a;
	a = b;
	b = c;
}

int Cantor(vector<vector<int>>& nums) {
	int x = 0;
	vector<int> A(n * n, 0);
	for (int i = 0; i < n * n; i++)
		for (int j = i + 1; j < n * n; j++)
			if (nums[j / n][j % n] < nums[i / n][i % n]) A[i]++;

	for (int i = 0; i < n * n; i++)
		x += A[i] * factorial[n * n - i - 1];
	return x;
}

class EightPuzzle {
public:
	vector<vector<int>> S; //九宫格
	int can;       //康托展开值
	int tag;     //有无解
	EightPuzzle() {};
	EightPuzzle(vector<vector<int>>& input);
	void print();
	void BfsSolve(EightPuzzle target);
	void PrintSolve(EightPuzzle Sg);
};

EightPuzzle::EightPuzzle(vector<vector<int>>& input) {
	S.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			S[i][j] = input[i][j];
	can = Cantor(S);
}

void EightPuzzle::print() {
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
vector<EightPuzzle> parent(365000,0); //记录父节点的康托展开
map<int,int> m;
void EightPuzzle::BfsSolve(EightPuzzle target) {
	if (can == target.can) {
		tag = can;
		return;
	}
	queue<EightPuzzle> q;
	q.push(S);
	parent[can] = S;
	while (!q.empty()) {
		EightPuzzle temp = q.front();
		vector<vector<int>> ts = temp.S;
		//awrhawrhawrhawhawrhrwha
		if(m[can]) continue;
		m[can]++;
		q.pop();
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
				parent[s.can] = temp;
				if (s.can == target.can) {
					tag = s.can;
					return;
				}
				q.push(s);
				swap(ts[x + movex[i]][y + movey[i]], ts[x][y]);    //归位
			}
		}
	}
	tag = 0;
}

void EightPuzzle::PrintSolve(EightPuzzle Sg) {
	if (!tag) {
		cout << "此状态无解\n";
		return;
	}
	if (can == Sg.can) {
		cout << "最少步解法有0步\n";
		print();
		return;
	}
	int temp = Sg.can;
	vector<EightPuzzle> ans;
	ans.push_back(Sg);
	do {
		ans.push_back(parent[temp]);
		temp = parent[temp].can;
	} while (parent[temp].can != can);
	cout << "最少步解法有" << ans.size() << "步,具体步骤如下:\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		ans[i].print();
	}
}

int main() {
	vector<vector<int>> input(n, vector<int>(n)), target = { {1,2,3},{8,0,4},{7,6,5} };
	cout << "请输入初始九宫格(用0表示空格):\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}
	EightPuzzle S0(input);
	EightPuzzle Sg(target);
	cout << "初始状态为\n";
	S0.print();
	cout << "目标状态为\n";
	Sg.print();
	S0.BfsSolve(Sg);
	S0.PrintSolve(Sg);
	return 0;
}

//2 8 3 1 0 4 7 6 5
//2 1 3 8 0 4 7 6 5