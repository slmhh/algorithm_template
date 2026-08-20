#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

struct node {
    int coe;  //系数
    int exp;  //指数
    char x; //变量
    node* next;
    node() :coe(0), exp(0), next(NULL) {};
};

//链表
class poly {
public:
    node* head;
    poly() { head = new node(); };
    void insert(node* num);
    void inputpoly(ll n);
    void outputpoly();
    poly add(poly& t1, poly& t2);
};

//插入
void poly::insert(node* num) {
    node* temp = new node();
    temp = head;
    while (temp->next != NULL && temp->next->exp < num->exp) {  //从小到大
        temp = temp->next;
    }
    num->next = temp->next;
    temp->next = num;
}

//多项式的输入
void poly::inputpoly(ll n) {
    for (int i = 0; i < n; i++) {
        node* t = new node();
        cin >> t->coe;
        t->x = getchar();  //变量的输入
        getchar();  //^
        cin >> t->exp;
        insert(t);
    }
}

//多项式的输出
void poly::outputpoly() {
    node* temp = new node();
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
        if (temp->coe > 0 && temp != head->next) cout << "+"; //输出加号
        cout << temp->coe << temp->x << "^" << temp->exp;
    }
    cout << "\n";
}

//多项式相加
poly poly::add(poly& t1, poly& t2) {
    poly ans;
    node* i = new node(), * j = new node();
    i = t1.head, j = t2.head;
    while (i != NULL || j != NULL) {
        node* temp = new node();
        if (i->exp == j->exp) {
            temp->exp = i->exp;
            temp->coe = i->coe + j->coe;
            temp->x = i->x;
            if (temp->coe != 0) ans.insert(temp);  //结果不为零
            i = i->next, j = j->next;
        }
        else {
            if (i != NULL && (i->exp < j->exp || j == NULL)) {
                temp->exp = i->exp;
                temp->coe = i->coe;
                temp->x = i->x;
                ans.insert(temp);
                i = i->next;
            }
            else if (j != NULL && (i->exp > j->exp || i == NULL)) {
                temp->exp = j->exp;
                temp->coe = j->coe;
                temp->x = j->x;
                ans.insert(temp);
                j = j->next;
            }
        }
    }
    return ans;
}

int main() {
    ll la, lb;
    poly a, b, ans;
    cout << "请输入第一个多项式的项数：\n";
    cin >> la;
    cout << "请输入第一个多项式: \n";
    a.inputpoly(la);
    cout << "请输入第二个多项式的项数：\n";
    cin >> lb;
    cout << "请输入第二个多项式: \n";
    b.inputpoly(lb);
    ans = ans.add(a,b);
    cout << "两多项式相加的结果为: \n";
    ans.outputpoly();
    return 0;
}