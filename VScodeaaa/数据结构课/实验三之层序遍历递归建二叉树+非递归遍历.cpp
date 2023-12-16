#include<bits/stdc++.h>
using namespace std;

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
        int depth;
        Bitree(){root = new Node<T>;depth = 0;};
        void Build(string str,Node<T> *temp,int idx);
        void Front(Node<T> *temp);
        void Middle(Node<T> *temp);
        void Back(Node<T> *temp);  
        void level(Node<T> *temp);
        void Draw();
};

//用层次遍历的递归建二叉树
template<typename T>
void Bitree<T>::Build(string str,Node<T> *temp,int idx){
    if(idx * 2 + 1 < str.size() && str[idx * 2 + 1] != '*'){
        temp->left = new Node<T>;
        temp->left->date = str[idx * 2 + 1];
        Build(str,temp->left,idx * 2 + 1);  //递归建立左子树
    }
    if(idx * 2 + 2 < str.size() && str[idx * 2 + 2] != '*'){
        temp->right = new Node<T>;
        temp->right->date = str[idx * 2 + 2];
        Build(str,temp->right,idx * 2 + 2);  //递归建立右子树
    }
}


//非递归先序遍历
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
template<typename T>
void Bitree<T>::Draw(){
    //w:二叉树宽度,site:该编号的横坐标,h:该编号的纵坐标
    int w = depth + 1,site[30] = {0},h[30] = {0},t;
    Node<T>* temp = new Node<T>;
    char g[100][100]; //g画布
    //初始化g
    for(int i = 0;i < w * 2 + 1;i++)
        for(int j = 0;j <= w * 4 + 1;j++) g[i][j] = ' ';
    site[root->date - 'A'] = w * 2 + 1,h[root->date] = 0; //site,h初始化
    queue<Node<T>*> s;
    s.push(root);
    //画出每一个结点
    while(!s.empty()){
        temp = s.front();
        s.pop();
        t = temp->date - 'A';
        g[h[t]][site[t]] = temp->date;
        //画左子树
        if(temp->left != NULL){
            g[h[t] + 1][site[t] - 1] = '/';
            site[temp->left->date - 'A'] =  site[t] - 2;
            h[temp->left->date - 'A'] = h[t] + 2;
            s.push(temp->left);
        }
        //画右子树
        if(temp->right != NULL){
            g[h[t] + 1][site[t] + 1] = '\\';
            site[temp->right->date - 'A'] =  site[t] + 2;
            h[temp->right->date - 'A'] = h[t] + 2;
            s.push(temp->right);
        }
    }
    //输出画的二叉树
    cout << "该二叉树的逻辑结构为:\n";
    for(int i = 0;i < w * 2 + 1;i++){
        for(int j = 1;j <= w * 4 + 1;j++)
            cout << g[i][j];
        cout << "\n";
    }
}

//层次遍历
template<typename T>
void  Bitree<T>::level(Node<T> *temp){
    if(!temp) return;
    queue<Node<T> *> q;
    Node<T> *t = new Node<T>;
    q.push(temp);
    while(!q.empty()){
        t = q.front();
        q.pop();
        cout << t->date;
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
}

int main(){
    string str;
    cout << "请输入带带外部结点的层次遍历序列:\n"; 
    cin >> str;
    Bitree<char> a;
    a.depth = (int)(log(str.size()));
    a.root->date = str[0];
    a.Build(str,a.root,0);
    a.Draw();
    cout << "先序遍历为:\n";
    a.Front(a.root);
    cout << "中序遍历为:\n";
    a.Middle(a.root);
    cout << "后序遍历为:\n";
    a.Back(a.root);
	cout << "层次遍历为:\n";
	a.level(a.root);
    return 0;
}