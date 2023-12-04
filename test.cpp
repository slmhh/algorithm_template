#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PLL;
const int N = 1e5 + 7;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    priority_queue<ll,vector<ll>,greater<ll> > right;
	priority_queue<ll,vector<ll> > left;
	ll n,mid,t;
	cin >> n;
	cin >> mid;
	cout << mid << "\n";
	for(int i = 1;i < n;i++){
		if(i & 1){
			cin >> t;
			left.push(t);
			if(left.top() > mid){
				t = left.top();
				left.push(mid);
				mid = t;
			}
			if(!right.empty() && right.top() < mid){
				t = right.top();
				right.push(mid);
				mid = t;
			}
		}
		else{
			cin >> t;
			right.push(t);
			if(!right.empty() && right.top() < mid){
				t = right.top();
				right.push(mid);
				mid = t;
			}
			if(!left.empty() && left.top() > mid){
				t = left.top();
				left.push(mid);
				mid = t;
			}
			cout << mid << "\n";
		}
	}
    return 0;
}
