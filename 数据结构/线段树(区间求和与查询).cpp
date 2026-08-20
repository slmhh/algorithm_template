#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegmentTree{
    ll n;
    struct info{
        ll data,tag;
        info():data(0),tag(0){};
        info operator+(info& b){
            info res;
            res.data = data + b.data;
            return res;
        };
    };

    vector<info> tr;
    SegmentTree(vector<ll>& nums){
        n = nums.size() - 1;
        tr.resize(n << 2);
        build(1,n,1,nums);
    }

    void push_up(ll p){
        tr[p] = tr[p << 1] + tr[(p << 1) | 1];
    }

    void f(ll p,ll l,ll r,ll x){
        tr[p].tag += x;
        tr[p].data += x * (r - l + 1);
    }

    void push_down(ll p,ll l,ll r){
        ll mid = (l + r) >> 1;
        f(p << 1,l,mid,tr[p].tag);
        f(p << 1 | 1,mid + 1,r,tr[p].tag);
        tr[p].tag = 0;
    }

    void build(ll l,ll r,ll p,vector<ll>& nums){
        if(l == r){
            tr[p].data = nums[l];
            return;
        }
        ll m = (l + r) >> 1;
        build(l,m,p << 1,nums),build(m + 1,r,(p << 1) | 1,nums);
        push_up(p);
    }

    void update(ll l,ll r,ll s,ll t,ll p,ll c){
        if(l <= s && t <= r){
            f(p,s,t,c);
            return;
        }
        push_down(p,s,t);
        ll m = (s + t) >> 1;
        if(l <= m) update(l,r,s,m,p << 1,c);
        if(r > m) update(l,r,m + 1,t,(p << 1) | 1,c);
        push_up(p);
    }

    info query(ll l,ll r,ll s,ll t,ll p){
        if(l <= s && t <= r) return tr[p];
        push_down(p,s,t);
        ll m = (s + t) >> 1;
        info left,right;
        if(l <= m) left = query(l,r,s,m,p << 1);
        if(r > m) right = query(l,r,m + 1,t,(p << 1) | 1);
        return left + right;
    }

    void update(ll l,ll r,ll x){
        update(l,r,1,n,1,x);
    }

    info query(ll l,ll r){
        return query(l,r,1,n,1);
    }
};

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m,op,t1,t2,k;
    cin >> n >> m;
    vector<ll> nums(n + 1);
    for(ll i = 1;i <= n;i++) cin >> nums[i];
    SegmentTree t(nums);
    while(m--){
        cin >> op >> t1 >> t2;
        if(op == 1){
            cin >> k;
            t.update(t1,t2,k);
        }
        else{
            cout << t.query(t1,t2).data << "\n";
        }
    }
    return 0;
}