#include<bits/stdc++.h>
using namespace std;

//ABCD*EFGH*****L

template<typename T>
struct Node{
    T date;
    Node* left;
    Node* right;
    Node(){left = NULL,right = NULL;};
};

//二叉树类
template<typename T>
class Bitree{
    public:
        Node<T>* root;
        Bitree(){root = new Node<T>;};
        void Build(string str,Node<T> *temp,int idx);
        void Front(Node<T> *temp);
        void Middle(Node<T> *temp);
        void Back(Node<T> *temp);
};

//用层次遍历的递归建二叉树
template<typename T>
void Bitree<T>::Build(string str,Node<T> *temp,int idx){
    if(idx * 2 + 1 < str.size() && str[idx * 2 + 1] != '*'){
        temp->left = new Node<T>;
        temp->left->date = str[idx * 2 + 1];
        Build(str,temp->left,idx * 2 + 1);
    }
    if(idx * 2 + 2 < str.size() && str[idx * 2 + 2] != '*'){
        temp->right = new Node<T>;
        temp->right->date = str[idx * 2 + 2];
        Build(str,temp->right,idx * 2 + 2);
    }
}


//非递归后序遍历
template<typename T>
void Bitree<T>::Front(Node<T> *temp){
    if(!temp) return;
    stack<Node<T>*> s;
    Node<T> *t = new Node<T>;
    s.push(temp);
    while(!s.empty()){
        t = s.top();
        s.pop();
        cout << t->date;
        if(t->right) s.push(t->right);
        if(t->left) s.push(t->left);
    }
    cout << "\n";
}

//非递归中序遍历
template<typename T>
void Bitree<T>::Middle(Node<T> *temp){
    if(!temp) return;
    stack<Node<T>*> s;
    Node<T> *t = new Node<T>;
    while(temp || !s.empty()){
        while(temp){
            s.push(temp);
            temp = temp->left;
        }
        if(!s.empty()){
            t = s.top();
            s.pop();
            cout << t->date;
            temp = t->right;
        }
    }
    cout << "\n";
}

//非递归后序遍历
template<typename T>
void Bitree<T>::Back(Node<T> *temp){
    if(!temp) return;
    stack<Node<T>*> s;
    stack<int> tag;
    Node<T> *t = new Node<T>;
    while(temp || !s.empty()){
        while(temp){
            s.push(temp);
            tag.push(1);
            temp = temp->left;
        }
        if(!s.empty()){
            t = s.top();
            s.pop();
            int flag = tag.top();
            tag.pop();
            if(flag == 1){
                s.push(t);
                tag.push(2);
                temp = t->right;
            }
            else cout << t->date;
        }
    }
    cout << "\n";
}

//画出二叉树的逻辑结构
void draw(string str){
    //w:二叉树宽度,site:该编号的横坐标,h:该编号的纵坐标
    int w = (int)(log(str.size()) + 1),site[30],h[30],t;
    char g[100][100]; //画布
    //初始化g
    for(int i = 0;i < w * 2 + 1;i++)
        for(int j = 0;j <= w * 4 + 1;j++) g[i][j] = ' ';
    g[0][(w * 2 + 1)] = str[0];
    site[str[0] - 'A'] = w * 2 + 1,h[str[0] - 'A'] = 0;
    //画出每一个结点
    for(int i = 0;i < str.size();i++){
        t = str[i] - 'A';
        //画左结点
        if(i * 2 + 1 < str.size() && str[i * 2 + 1] != '*'){
            g[h[t] + 1][site[t] - 1] = '/';
            g[h[t] + 2][site[t] - 2] = str[i * 2 + 1];
            site[str[i * 2 + 1] - 'A'] =  site[t] - 2;
            h[str[i * 2 + 1] - 'A'] = h[t] + 2;
        } 
        //画右结点
        if(i * 2 + 2 < str.size() && str[i * 2 + 2] != '*'){
            g[h[t] + 1][site[t] + 1] = '\\';
            g[h[t] + 2][site[t] + 2] = str[i * 2 + 2];
            site[str[i * 2 + 2] - 'A'] =  site[t] + 2;
            h[str[i * 2 + 2] - 'A'] = h[t] + 2;
        }
    }
    //输出画的二叉树
    for(int i = 0;i < w * 2 + 1;i++){
        for(int j = 1;j <= w * 4 + 1;j++)
            cout << g[i][j];
        cout << "\n";
    }
}

int main(){
    string str;
    cin >> str;
    cout << "该二叉树的逻辑结构为:\n";
    draw(str);
    Bitree<char> a;
    a.root->date = str[0];
    a.Build(str,a.root,0);
    cout << "前序遍历为:\n";
    a.Front(a.root);
    cout << "中序遍历为:\n";
    a.Middle(a.root);
    cout << "后序遍历为:\n";
    a.Back(a.root);
    return 0;
}