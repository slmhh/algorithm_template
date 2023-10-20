    #include<bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    const int N = 1e5 + 10;

    struct value{
        ll t,c;
    }fell[N];

    bool cmp(value a,value b){
        if(a.t != b.t) return a.t < b.t;
        return a.c > b.c;
    }

    int main(){
        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        ll n,m,k;
        cin >> n >> m >> k;
        for(int i = 1;i <= n;i++){
            cin >> fell[i].t >> fell[i].c;
        }
        sort(fell,fell + n,cmp);
        int i;
        fell[0].t = k,fell[0].c = 0;
        for(i = n;i > 0;i--){
            if((fell[i].t - fell[i - 1].t)*fell[i].c <= m){
                m -= (fell[i].t - fell[i - 1].t)*fell[i].c;
                fell[i - 1].c += fell[i].c;
                fell[i].t = fell[i - 1].t;
            }
            else{
                fell[i].t -= m / fell[i].c;
                i--;
                break;
            }
        }
        cout << max(fell[i + 1].t,k) << "\n";
        return 0;
    }