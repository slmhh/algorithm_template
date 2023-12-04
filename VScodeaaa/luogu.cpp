#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PLL;
const int N = 1e5 + 7;


vector<fun> nums;
struct fun{
	ll a,b,c;
};
struct val{
	ll v,idx;
};
bool cmp(val a,val b){
	ll t1,t2;
	fun temp = nums[a.idx];
	t1 = temp.a * a.v * a.v + temp.b * a.v + temp.c;
	temp = nums[b.idx];
	t2 = temp.a * b.v * b.v + temp.b * b.v + temp.c;
	return t1 < t2;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    priority_queue<val,vector<val>,cmp() > heap;
	ll n;
	cin >> n;
	fun temp;
	val t;
	for(int i = 0;i < n;i++){
		cin >> temp.a >> temp.b >> temp.c;
		nums.push_back(temp);
		t.v = - (temp.c / 2 / temp.a);
		t.idx = i;
		if()
		heap.push(t);
		t.v++;
		heap.push(t);
	}
	while(m--){
		t = heap.top()
		heap.pop();

	}
    return 0;
}