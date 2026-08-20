#include<bits/stdc++.h>
const int N = 1e6;

struct node{
    int l,r,k;
}q[N];

int pos[N],ans[N],cnt[N],a[N];

bool cmp(node a,node b){
    if(pos[a.l] != pos[b.l]){
        return pos[a.l] < pos[b.l];
    }
    if(pos[a.l] & 1) return a.r > b.r;
    return a.r < b.r;
}

int ANS = 0;
void add(int x){
    cnt[a[x]]++;
    if(cnt[a[x]] == 1) ANS++;
}

void del(int x){
    cnt[a[x]]--;
    if(cnt[a[x]] == 0) ANS--;
}

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int n;
    std::cin >> n;
    int bolck = std::sqrt(n);
    for(int i = 1;i <= n;i++){
        std::cin >> a[i];
        pos[i] = (i - 1) / bolck + 1;
    }
    int m;
    std::cin >> m;
    for(int i = 1;i <= m;i++){
        std::cin >> q[i].l >> q[i].r;
        q[i].k = i;
    }
    std::sort(q + 1,q + 1 + m,cmp);
    int L = 1,R = 0;
    for(int i = 1;i <= m;i++){
        while(L < q[i].l) del(L++);
        while(R > q[i].r) del(R--);
        while(L > q[i].l) add(--L);
        while(R < q[i].r) add(++R);
        ans[q[i].k] = ANS;
    }
    for(int i = 1;i <= m;i++){
        std::cout << ans[i] << "\n";
    }
    return 0;
}