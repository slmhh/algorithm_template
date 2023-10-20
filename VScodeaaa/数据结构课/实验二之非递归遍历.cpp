#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Node{
    T date;
    Node* left;
    Node* right;
    Node(){left = NULL,right = NULL;};
};

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
    string str;
    cin >> str;
    cout << str <<"\n";
    Bitree<char> a;
    a.root->date = str[0];
    a.Build(str,a.root,0);
    a.Front(a.root);
    a.Middle(a.root);
    a.Back(a.root);
    return 0;
}