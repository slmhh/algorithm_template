#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

struct date {
    int coe;  //系数
    int exp;  //指数
    char x;   //变量
};

bool cmp(date a, date b) { return a.exp < b.exp; }

template<typename T>
class poly {
public:
    T nums[N];
    int size;
    poly() { size = 0; };
    void Sort() { sort(nums, nums + size, cmp); };
    void Push_back(T d) { nums[size] = d, size++; };
    void Inputpoly(int len);
    void Outputpoly();
    int Size() { return size; };
    poly<T> Add(poly<T>& t1, poly<T>& t2);
};

//多项式的输入
template<typename T>
void poly<T>::Inputpoly(int len) {
    for (int i = 0; i < len; i++) {
        T t;
        cin >> t.coe;
        t.x = getchar();  //变量的输入
        getchar();  //^
        cin >> t.exp;
        Push_back(t);

    }
}

//多项式的输出
template<typename T>
void poly<T>::Outputpoly() {
    for (int i = 0; i < Size(); i++) {
        if (nums[i].coe > 0 && i != 0) cout << "+"; //输出加号
        cout << nums[i].coe << nums[i].x << "^" << nums[i].exp;
    }
    cout << "\n";
}

//多项式相加的实现
template<typename T>
poly<T> poly<T>::Add(poly<T>& t1, poly<T>& t2) {
    poly<T> ans;
    T temp;
    t1.Sort(), t1.Sort();
    int i = 0, j = 0;;
    while (i < t1.Size() || j < t2.Size()) {
        if (t1.nums[i].exp == t2.nums[j].exp) {
            temp.exp = t1.nums[i].exp;
            temp.coe = t1.nums[i].coe + t2.nums[j].coe;
            temp.x = t1.nums[i].x;
            if (temp.coe != 0) ans.Push_back(temp);  //结果不为零
            i++, j++;
        }
        else {
            if (i < t1.Size() && (t1.nums[i].exp < t2.nums[j].exp || j >= t2.Size())) {
                temp.exp = t1.nums[i].exp;
                temp.coe = t1.nums[i].coe;
                temp.x = t1.nums[i].x;
                ans.Push_back(temp);
                i++;
            }
            else if (j < t2.Size() && (t1.nums[i].exp > t2.nums[j].exp || i >= t1.Size())) {
                temp.exp = t2.nums[j].exp;
                temp.coe = t2.nums[j].coe;
                temp.x = t2.nums[i].x;
                ans.Push_back(temp);
                j++;
            }
        }
    }
    return ans;
}

int main() {
    int la, lb;
    cout << "请输入第一个多项式的项数：\n";
    cin >> la;
    poly<date> a, b;
    cout << "请输入第一个多项式: \n";
    a.Inputpoly(la);
    cout << "请输入第二个多项式的项数：\n";
    cin >> lb;
    cout << "请输入第二个多项式: \n";
    b.Inputpoly(lb);
    poly<date> ans;
    ans = ans.Add(a, b);
    cout << "两多项式相加的结果为: \n";
    ans.Outputpoly();
    return 0;
}