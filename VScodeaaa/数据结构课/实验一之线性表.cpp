#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

char x; //变量
struct date{
    int coe;  //系数
    int exp;  //指数
};

bool cmp(date a,date b){return a.exp < b.exp;}

//多项式的输入
void inputpoly(vector<date> &t){
    for(int i = 0;i < t.size();i++){
        cin >> t[i].coe;
        x = getchar();  //变量的输入
        getchar();  //^
        cin >> t[i].exp;
    }
}

//多项式的输出
void outputpoly(vector<date> &t){
    for(int i = 0;i < t.size();i++){
        if(t[i].coe > 0 && i != 0) cout << "+"; //输出加号
        cout << t[i].coe << x << "^" << t[i].exp;
    }
    cout << "\n";
}

//多项式相加的实现
vector<date> add(vector<date> &t1,vector<date> &t2){
    vector<date> ans;
    date temp;
    sort(t1.begin(),t1.end(),cmp);
    sort(t2.begin(),t2.end(),cmp);
    ll i = 0,j = 0;;
    while(i < t1.size() || j < t2.size()){
        if(t1[i].exp == t2[j].exp){
            temp.exp = t1[i].exp;
            temp.coe = t1[i].coe + t2[j].coe;
            if(temp.coe != 0) ans.push_back(temp);  //结果不为零
            i++,j++;
        }
        else{
            if(i < t1.size() && (t1[i].exp < t2[j].exp || j >= t2.size())){
                temp.exp = t1[i].exp;
                temp.coe = t1[i].coe;
                ans.push_back(temp);
                i++;
            }
            else if(j < t2.size() && (t2[i].exp < t1[i].exp || i >= t1.size())){
                temp.exp = t2[j].exp;
                temp.coe = t2[j].coe;
                ans.push_back(temp);
                j++;
            }
        } 
    }
    return ans;
}

int main(){
    ll la,lb;
    cout << "请输入第一个多项式的项数：\n";
    cin >> la;
    vector<date> a(la);
    cout << "请输入第一个多项式: \n";
    inputpoly(a);
    cout << "请输入第二个多项式的项数：\n";
    cin >> lb;
    vector<date> b(lb);
    cout << "请输入第二个多项式: \n";
    inputpoly(b);
    vector<date> ans = add(a,b);
    cout << "两多项式相加的结果为: \n";
    outputpoly(ans);
    return 0;
}