#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;
const int N = 1e8;
const double eps = 1e-4;

int main() {
	double n = 23333333,x;
	double h = 11625907.5798,t;
	for(x = 1;x <= 23333333;x++){
		t = - (x * x / n * log2(x / n) + (n - x) * (n - x) / n * log2((n - x) / n));
		if(fabs(h - t) <= eps){
			cout << (int)x << "\n";
			break;
		}
	}
	return 0;
}

/*11027421*/