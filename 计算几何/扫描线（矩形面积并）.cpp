#include<bits/stdc++.h>
using i64 = long long;

struct ScanLine{
	std::vector<i64> cover,weight,num;
	std::vector<std::array<i64,4>> side;
	std::map<i64,i64> mp;
	i64 n;
	ScanLine(){};
	ScanLine(i64 N):n(N),cover(N << 3),weight(N << 3),num((N << 1) + 1){}

    void push_up(i64 p,i64 l,i64 r){
        if(cover[p]) weight[p] = num[r] - num[l];
		else if(l + 1 == r) weight[p] = 0;
		else weight[p] = weight[(p << 1) | 1] + weight[p << 1];
    }

    void update(i64 l,i64 r,i64 c,i64 s,i64 t,i64 p){
        if(l <= s && t <= r){
            cover[p] += c;
			push_up(p,s,t);
            return;
        }
		if(s + 1 == t) return ;
        i64 m = s + ((t - s) >> 1);
        if(l <= m) update(l,r,c,s,m,p << 1);
        if(r > m) update(l,r,c,m,t,(p << 1) | 1);
        push_up(p,s,t);
    }

	void addRectangle(i64 x1,i64 y1,i64 x2,i64 y2){
		side.push_back({x1,y1,y2,1});
		side.push_back({x2,y1,y2,-1});
		mp[y1]++,mp[y2]++;
	}

	i64 run(){
		i64 res = 0,idx = 0;
		for(auto& i : mp){
			i.second = ++idx;
			num[idx] = i.first;
		}
		sort(side.begin(),side.end());
		update(mp[side[0][1]],mp[side[0][2]],1,1,2 * n,1);
		for(int i = 1;i < side.size();i++){
			auto [x,y1,y2,tag] = side[i];
			res += (x - side[i - 1][0]) * weight[1];
			update(mp[y1],mp[y2],tag,1,2 * n,1);
		}
		return res;
	}
};

int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	i64 T = 1;
	// cin >> T;
	while(T--){
		i64 n;
		std::cin >> n;
		ScanLine sl(n);
		for(int i = 1;i <= n;i++){
			i64 x1,y1,x2,y2;
			std::cin >> x1 >> y1 >> x2 >> y2;
			sl.addRectangle(x1,y1,x2,y2);
		}
		std::cout << sl.run() << "\n";
	}
	return 0;
}
