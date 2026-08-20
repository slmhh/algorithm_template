#include<bits/stdc++.h>
using namespace std;

//ABCD*EFGH*****L
/*
该二叉树的逻辑结构为:
      A      
     / \     
    B   C    
   /   / \   
  D   E   F  
 / \       \ 
G   H       L
前序遍历为:
ABDGHCEFL
中序遍历为:
GDHBAECFL
后序遍历为:
GHDBELFCA
*/


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
        void Build(string str,string str1,Node<T> *temp);
        void Front(Node<T> *temp);
        void Middle(Node<T> *temp);
        void Back(Node<T> *temp);
};


//用先序遍历和中序遍历建树
template<typename T>
void Bitree<T>::Build(string str,string str1,Node<T> *temp){
    int i = 0;
    //寻找根结点的位置
    for(;i < str1.size();i++)
        if(str1[i] == str[0]) break;
    if(i != 0){
        temp->left = new Node<T>;
        temp->left->date = str[1];
        //递归建立左子树
        Build(str.substr(1,i),str1.substr(0,i),temp->left);
    }
    if(i != str.size() - 1){
        temp->right = new Node<T>;
        temp->right->date = str[i + 1];
        //递归建立右子树
        Build(str.substr(i + 1,str.size() - i - 1),str1.substr(i + 1,str1.size() - i - 1),temp->right);
    }
    
}

/*
//用后序序遍历和中序遍历建树
void Bitree<T>::Build(string str,string str1,Node<T> *temp){
    int i = 0;
    //寻找根结点的位置
    for(;i < str.size();i++)
        if(str[i] == str1[str1.size() - 1]) break;
    if(i != 0){
        temp->left = new Node<T>;
        temp->left->date = str1[i - 1];
        //递归建立左子树
        Build(str.substr(0,i),str1.substr(0,i),temp->left);
    }
    if(i != str.size() - 1){
        temp->right = new Node<T>;
        temp->right->date = str1[str1.size() - 1];
        //递归建立右子树
        Build(str.substr(i + 1,str.size() - i - 1),str1.substr(i + 1,str1.size() - i - 2),temp->right); 
    }
}*/

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

int main(){
    string str,str1;
    cout << "请输入该二叉树的中序遍历:\n";
    cin >> str;
    cout << "请输入该二叉树的后序遍历:\n";
    cin >> str1;
    Bitree<char> a;
    a.root->date = str[0];
    a.Build(str,str1,a.root);
    cout << "前序遍历为:\n";
    a.Front(a.root);
    cout << "中序遍历为:\n";
    a.Middle(a.root);
    cout << "后序遍历为:\n";
    a.Back(a.root);
    return 0;
}