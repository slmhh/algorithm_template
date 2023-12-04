#include <iostream>
typedef long long LL,ll;
LL n, a[100005]; //原数组 
LL d[270000];  //线段树 
LL b[270000];  //懒惰标记 


//P3372 【模板】线段树 1
void build(LL l, LL r, LL p) {  // l:区间左端点 r:区间右端点 p:节点标号
    if (l == r) {		//如果区间长为1 
        d[p] = a[l];  //将节点赋值   a下标是l！！！！！
        return;
    }
    LL m = l + ((r - l) >> 1);  //取区间中点 
    build(l, m, p << 1), build(m + 1, r, (p << 1) | 1);  //分别建立左右子树  第一个是字母l！！！！！
    d[p] = d[p << 1] + d[(p << 1) | 1];   //求和
}

void update(LL l, LL r, LL c, LL s, LL t, LL p) { // s:要修改区间的左端点  t:要修改区间的左端点  c:加上(更新 )的值 
	if (l <= s && t <= r) {
		d[p] += (t - s + 1) * c; // 如果区间被包含了，直接得出答案
		b[p] += c; //懒惰标记 
		return;
	}
	LL m = s + ((t - s) >> 1);  //取区间中点 
	if (b[p]){  //如果有懒惰标记 
		d[p << 1] += b[p] * (m - s + 1); //左结点的区间长度乘c
		d[(p << 1) | 1] += b[p] * (t - m);  //右结点的区间长度乘c
		b[p << 1] += b[p];     //左结点添加懒惰标记 
		b[(p << 1) | 1] += b[p];    //右结点添加懒惰标记 
	}
	b[p] = 0; //懒惰标记归零
	if (l <= m)
	    update(l, r, c, s, m, p << 1);  //本行和下面的一行用来更新p*2和p*2+1的节点
	if (r > m) 
		update(l, r, c, m + 1, t, (p << 1) | 1);
	d[p] = d[p << 1] + d[(p << 1) | 1];  //更新该节点区间和
}

LL getsum(LL l, LL r, LL s, LL t, LL p) {
    if (l <= s && t <= r) return d[p];
    LL m = s + ((t - s) >> 1);
    if (b[p]){
        d[p << 1] += b[p] * (m - s + 1);  //同update
        d[(p << 1) | 1] += b[p] * (t - m);
        b[p << 1] += b[p];
        b[(p << 1) | 1] += b[p];
	}
    b[p] = 0;
    LL sum = 0;
    if (l <= m)
        sum = getsum(l, r, s, m, p << 1);  // 本行和下面的一行用来更新p*2和p*2+1的答案
    if (r > m) 
        sum += getsum(l, r, m + 1, t, (p << 1) | 1);
    return sum;
}

int main() {
    std::ios::sync_with_stdio(0);
    LL q, op, i2, i3, i4;
    std::cin >> n >> q;
    for (LL i = 1; i <= n; i++) std::cin >> a[i];
    build(1, n, 1); //从1开始建立线段树
    while (q--) {
        std::cin >> op >> i2 >> i3;
        if(op == 2)
            std::cout << getsum(i2, i3, 1, n, 1) << std::endl;  // 直接调用操作函数
        else
            std::cin >> i4, update(i2, i3, i4, 1, n, 1);
    }
    return 0;
}

/*
    #include<bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    const int N = 1e6 + 10;

    struct node{
        ll date;
        ll lazytag;
    };

    ll n,nums[N];
    node linetree[2 * N + 100];

    void build(ll l,ll r,ll p){
        if(l == r){
            linetree[p].date = nums[l];
            return;
        }
        ll m = l + ((r - l) >> 1);
        build(l,m,p << 1),build(m + 1,r,(p << 1) | 1);
        linetree[p].date = linetree[p << 1].date + linetree[(p << 1) | 1].date;
    }

    void update(ll l,ll r,ll s,ll t,ll p,ll c){
        if(l <= s && t <= r){
            linetree[p].date += (t - s + 1) * c;
            linetree[p].lazytag += c;
            return;
        }
        ll m = s + ((t - s) >> 1);
        if(linetree[p].lazytag){
            linetree[p << 1].date += (m - s + 1) * linetree[p].lazytag;
            linetree[(p << 1) | 1].date += (t - m) * linetree[p].lazytag;
            linetree[p << 1].lazytag += linetree[p].lazytag;
            linetree[(p << 1) | 1].lazytag += linetree[p].lazytag;
        }
        linetree[p].lazytag = 0;
        if(l <= m)
            update(l,r,s,m,p << 1,c);
        if(r > m)
            update(l,r,m + 1,t,(p << 1) | 1,c);
        linetree[p].date = linetree[p << 1].date + linetree[(p << 1) | 1].date;
    }

    ll getsum(ll l,ll r,ll s,ll t,ll p){
        if(l <= s && t <= r) return linetree[p].date;
        ll m = s + ((t - s) >> 1);
        if(linetree[p].lazytag){
            linetree[p << 1].date += (m - s + 1) * linetree[p].lazytag;
            linetree[(p << 1) | 1].date += (t - m) * linetree[p].lazytag;
            linetree[p << 1].lazytag += linetree[p].lazytag;
            linetree[(p << 1 )| 1].lazytag += linetree[p].lazytag;
        }
        linetree[p].lazytag = 0;
        ll sum = 0;
        if(l <= m)
            sum = getsum(l,r,s,m,p << 1);
        if(r > m)
            sum += getsum(l,r,m + 1,t,(p << 1) | 1);
        return sum;
    }

    int main(){
        ll m,op,t1,t2,k;
        cin >> n >> m;
        for(int i = 1;i <= n;i++) cin >> nums[i];
        build(1,n,1);
        while(m--){
            cin >> op >> t1 >> t2;
            if(op == 1){
                cin >> k;
                update(t1,t2,1,n,1,k);
            }
            else{
                cout << getsum(t1,t2,1,n,1) << "\n";
            }
        }
        return 0;
    }
*/
