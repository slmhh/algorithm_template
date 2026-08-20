#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> mul(vector<int> &A,vector<int> &B){
	vector<int> C;
	if(A.size() < B.size()) return mul(B,A);
	int t;
	for(int i = 0;i < A.size() + B.size() - 1;i++){
		C.push_back(0);
	}
	for(int i = 0;i < B.size();i++){
		t = 0;
		for(int j = 0;j < A.size() || t;j++){
			if(j < A.size()) t += A[j] * B[i] + C[i + j];
			C[j + i] = t % 10;
			t /= 10;
		}
	}
	while(C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

int main(){
	string a,b;
	vector<int> A,B,C;
	
	cin >> a >> b;
	for(int i = a.size() - 1;i >= 0;i--) A.push_back(a[i] - '0');
	for(int i = b.size() - 1;i >= 0;i--) B.push_back(b[i] - '0');
	
	C = mul(A,B);
	
	for(int i = C.size() - 1;i >= 0;i--) cout << C[i];
	return 0;
}
