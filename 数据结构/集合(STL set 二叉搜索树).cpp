#include<bits/stdc++.h>
#define debug(x) cout << "#x" << x << endl;
#define all(x) (x).begin(),(x).end()
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        set<long long int> num;
        long long int n,t;
        cin >> n;
        for(int i = 0;i < n;i++){
            scanf("%lld",&t);
            num.insert(t);
        }
        cout << num.size() << endl;
    }
    return 0;
}
