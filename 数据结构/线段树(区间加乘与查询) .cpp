#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

struct SegmentTree{
    ll n,mod = 998244353;
    struct node{
        ll date = 0;
        ll add = 0;
        ll mu = 1;
    };
    vector<node> tr;
    SegmentTree(vector<ll>& nums){
        n = nums.size() - 1;
        tr.resize(n * 4 + 10);
        build(1,n,1,nums);
    }

    void push_up(ll p){
        tr[p].date = (tr[p << 1].date + tr[(p << 1) | 1].date) % mod;
    }

    void f(ll p,ll l,ll r,ll x,ll k){
        tr[p].date = (tr[p].date * k + x * (r - l + 1)) % mod;
        tr[p].mu = (tr[p].mu * k) % mod;
        tr[p].add = (tr[p].add * k % mod + x) % mod;
    }

    void push_down(ll p,ll l,ll r){
        ll mid = (l + r) >> 1LL;
        f(p << 1,l,mid,tr[p].add,tr[p].mu);
        f(p << 1 | 1,mid + 1,r,tr[p].add,tr[p].mu);
        tr[p].add = 0,tr[p].mu = 1;
    }

    void build(ll l,ll r,ll p,vector<ll>& nums){
        if(l == r){
            tr[p].date = nums[l];
            return;
        }
        ll m = l + ((r - l) >> 1);
        build(l,m,p << 1,nums),build(m + 1,r,(p << 1) | 1,nums);
        push_up(p);
    }
    //x is add,k is mul
    void update(ll l,ll r,ll s,ll t,ll p,ll x,ll k){
        if(l <= s && t <= r){
            f(p,s,t,x,k);
            return;
        }
        push_down(p,s,t);
        ll m = s + ((t - s) >> 1);
        if(l <= m) update(l,r,s,m,p << 1,x,k);
        if(r > m) update(l,r,m + 1,t,(p << 1) | 1,x,k);
        push_up(p);
    }

    ll query(ll l,ll r,ll s,ll t,ll p){
        if(l <= s && t <= r) return tr[p].date;
        push_down(p,s,t);
        ll m = s + ((t - s) >> 1);
        ll sum = 0;
        if(l <= m) sum = query(l,r,s,m,p << 1);
        if(r > m) sum = (sum + query(l,r,m + 1,t,(p << 1) | 1)) % mod;
        return sum;
    }

    void RangeMul(ll l,ll r,ll x){
        update(l,r,1,n,1,0,x);
    }

    void RangeAdd(ll l,ll r,ll x){
        update(l,r,1,n,1,x,1);
    }

    ll query(ll l,ll r){
        return query(l,r,1,n,1);
    }
};

int main(){
    ll n,q,m,op,l,r,k;
    cin >> n >> q >> m;
    vector<ll> nums(n + 1);
    for(int i = 1;i <= n;i++) cin >> nums[i];
    SegmentTree t(nums);
    t.mod = m;
    while(q--){
        cin >> op >> l >> r;
        if(op == 1){
            cin >> k;
            t.RangeMul(l,r,k);
        }
        else if(op == 2){
            cin >> k;
            t.RangeAdd(l,r,k);
        }
        else{
            cout << t.query(l,r) << "\n";
        }
    }
    return 0;
}