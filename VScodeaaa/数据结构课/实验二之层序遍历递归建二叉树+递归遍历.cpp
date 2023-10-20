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
    if(temp == NULL) return;
    cout << temp->date;
    Front(temp->left);
    Front(temp->right);
}

template<typename T>
void Bitree<T>::Middle(Node<T> *temp){
    if(temp == NULL) return;
    Middle(temp->left);
    cout << temp->date;
    Middle(temp->right);
}


template<typename T>
void Bitree<T>::Back(Node<T> *temp){
    if(temp == NULL) return;
    Back(temp->left);
    Back(temp->right);
    cout << temp->date;
}

int main(){
    string str;
    cin >> str;
    cout << str <<"\n";
    Bitree<char> a;
    a.root->date = str[0];
    a.Build(str,a.root,0);
    a.Front(a.root);
    cout << "\n";
    a.Middle(a.root);
    cout << "\n";
    a.Back(a.root);
    return 0;
}