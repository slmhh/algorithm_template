#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e8;

bool check(int n){
	int len = 0,temp = n,sum = 0,sum2 = 0;
	while(temp > 0){
		len++;
		sum += temp % 10;
		temp /= 10;
	}
	if(len & 1) return false;
	for(int i = 0;i < len / 2;i++){
		sum2 += n % 10;
		n /= 10;
	}
	if(sum == sum2 * 2) return true;
	return false;
}

int main() {
	int cnt = 0;
	for(int i = 1;i <= N;i++){
		if(check(i)) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}

/*4430091*/