#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    T date;  //数据
    int idx;  //编号
    vector<Node<T>*> son; //存储孩子编号
    Node<T>* pa;  //存储双亲编号
    Node<T>() { pa = NULL; };
};

template<typename T>
class Tree {
public:
    Node<T>* Root;
    Tree() { Root = new Node<T>;};
    Node<T>* findp(int p, Node<T>* t);
    void Printpa(int p);  //输出双亲
    void build();  //建树
    void Printbro(int p); //输出兄弟
    void Printson(int p); //输出孩子
    void Printgra(int p); //输出祖先
    void Printun(int p);  //输出子孙
};

//找到编号为p的结点
template<typename T>
Node<T>* Tree<T>::findp(int p, Node<T>* t) {
    if (t->idx == p) return t;
    if (t->son.size() == 0) return t;
    Node<T>* temp = new Node<T>;
    for (int i = 0; i < t->son.size(); i++) {
        temp = findp(p, t->son[i]);
        if (temp->idx == p) break;
    }
    if (temp == NULL) {
        cout << "没有编号为p的结点\n";
        return NULL;
    }
    return temp;
}

//建树
template<typename T>
void Tree<T>::build() {
    int n, t, m;
    Node<T>* temp = new Node<T>;
    cout << "请输入树节点的数量:\n";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        temp = findp(i, Root);
        cout << "请输入编号为" << i << "的结点的数值:\n";
        cin >> temp->date;
        cout << "请输入编号为" << i << "的结点的孩子数目:\n";
        cin >> m;
        if (m != 0) {
            cout << "请依次输入孩子结点的编号:\n";
            for (int j = 0; j < m; j++) {
                cin >> t;
                Node<T>* tempson = new Node<T>;
                tempson->idx = t;
                tempson->pa = temp;
                temp->son.push_back(tempson);
            }
        }
    }
}

//输出双亲
template<typename T>
void Tree<T>::Printpa(int p) {
    Node<T>* temp = new Node<T>;
    temp = findp(p, Root);
    if (temp == NULL)  return;  //没有p结点
    if (temp->pa == NULL) {  //p为根结点
        cout << "编号p没有双亲结点\n";
        return;
    }
    temp = temp->pa;
    cout << "编号p的双亲结点的编号为:" << temp->idx << " ，数值为:" << temp->date << "\n";
}

//输出兄弟
template<typename T>
void Tree<T>::Printbro(int p) {
    Node<T>* temp = new Node<T>;
    temp = findp(p, Root);
    if (temp == NULL)  return;  //没有p结点
    if (temp->pa == NULL) {  //p为根结点
        cout << "编号p没有双亲结点\n";
        return;
    }
    temp = temp->pa;
    if (temp->son.size() == 1) {
        cout << "编号p没有兄弟结点\n";
        return;
    }
    for (int i = 0; i < temp->son.size(); i++) {
        if (temp->son[i]->idx != p)
            cout << "编号p的兄弟结点的编号为:" << temp->son[i]->idx << " ，数值为:" << temp->son[i]->date << "\n";
    }
}

//输出孩子
template<typename T>
void Tree<T>::Printson(int p) {
    Node<T>* temp = new Node<T>;
    temp = findp(p, Root);
    if (temp == NULL)  return;  //没有p结点
    if (temp->son.size() == 0) { //p为叶结点
        cout << "编号p没有孩子结点\n";
        return;
    }
    for (int i = 0; i < temp->son.size(); i++)
        cout << "编号p的孩子结点的编号为:" << temp->son[i]->idx << " ，数值为:" << temp->son[i]->date << "\n";
}

//输出祖先
template<typename T>
void Tree<T>::Printgra(int p) {
    Node<T>* temp = new Node<T>;
    temp = findp(p, Root);
    if (temp == NULL)  return;  //没有p结点
    if (temp->pa == NULL) {
        cout << "编号p没有祖先结点\n";
        return;
    }
    while (temp->pa != NULL) {
        temp = temp->pa;
        if(temp->idx != p)
        	cout << "编号p的祖先结点的编号为:" << temp->idx << " ，数值为:" << temp->date << "\n";
    }
}

//输出子孙
template<typename T>
void Tree<T>::Printun(int p) {
    Node<T>* temp = new Node<T>;
    Node<T>* s = new Node<T>;
    queue<Node<T>*> t;
    bool flag = false;
    temp = findp(p, Root);
    if (temp == NULL)  return;  //没有p结点
    if (temp->son.size() == 0) {
        cout << "编号p没有子孙结点\n";
        return;
    }
    for (int i = 0; i < temp->son.size(); i++) {
        t.push(temp->son[i]);
        while (!t.empty()) {
            s = t.front();
            t.pop();
            flag = true;
            cout << "编号p的子孙结点的编号为:" << s->idx << " ，数值为:" << s->date << "\n";
            for (int j = 0; j < s->son.size(); j++) t.push(s->son[j]);
        }
    }
    if (flag == false) cout << "编号p没有子孙结点\n";
}


int main() {
    Tree<char> a;
    a.Root->idx = 1;
    a.build();
    int p;
    cout << "需要查找的结点编号:\n";
    cin >> p;
    a.Printbro(p);
    a.Printgra(p);
    a.Printpa(p);
    a.Printson(p);
    a.Printun(p);
    return 0;
}

/*
11
A
2
2 3
B
3
4 5 6
C
2
7 8
D
0
E
2
9 10
F
0
G
0
H
0
I
0
J
1
11
K
0
*/