#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Node{
	T date;
	int idx;
	vector<Node<T>*> son;
	Node<T>* pa;
	Node<T> (){pa = NULL;};
};

template<typename T>
class Tree{
	public:
		Node<T>* Root;
		Tree(){};
		Node<T> findp(int p,Node<T>* t);
		void Printpa(int p);
		void Printbro(int p);
		void Printson(int p);
		void Printgra(int p);
		void Printun(int p);
};

template<typename T>
Node<T>* Tree<T>::findp(int p,Node<T>* t){
	if(t->idx == p) return t;
	if(t->son.size() == 0) return NULL;
	Node<T>* temp = new Node<T>;
	for(int i = 0;i < t->son.size();i++){
		temp = findp(int p,t->son[i]);
		if(temp->idx == p) return temp;
	}
	cout << "没有编号为p的结点\n";
	return NULL;
}

template<typename T>
void Tree<T>::Printpa(int p){
	Node<T>* temp = new Node<T>;
	temp = findp(p,Root);
	if(temp == NULL)  return;  //没有p结点
	if(temp->pa == NULL){  //p为根结点
		cout << "编号p没有双亲结点\n";
		return;
	}
	temp = temp->pa;
	cout << "编号p的双亲结点的编号为：" << temp->idx << " ，数值为：" << temp->date << "\n";
}

template<typename T>
void Tree<T>::Printbro(int p){
	Node<T>* temp = new Node<T>;
	temp = findp(p,Root);
	if(temp == NULL)  return;  //没有p结点
	if(temp->pa == NULL){  //p为根结点
		cout << "编号p没有双亲结点\n";
		return;
	}
	temp = temp->pa;
	if(temp->son.size() == 1){
		cout << "编号p没有兄弟结点\n";
		return;
	}
	for(int i = 0;i < temp->son.size();i++){
		if(temp->son[i]->date != p)
			cout << "编号p的兄弟结点的编号为：" << temp->son[i]->idx << " ，数值为：" << temp->son[i]->date << "\n";
	}
}

template<typename T>
void Tree<T>::Printson(int p){
	Node<T>* temp = new Node<T>;
	temp = findp(p,Root);
	if(temp == NULL)  return;  //没有p结点
	if(temp->son.size() == 0){ //p为叶结点
		cout << "编号p没有儿子结点\n";
		return;
	}
	for(int i = 0;i < temp->son.size();i++)
		cout << "编号p的儿子结点的编号为：" << temp->son[i]->idx << " ，数值为：" << temp->son[i]->date << "\n";
}

template<typename T>
void Tree<T>::Printgra(int p){
	Node<T>* temp = new Node<T>;
	temp = findp(p,Root);
	if(temp == NULL)  return;  //没有p结点
	if(temp->pra == NULL || temp->pra->pra == NULL){
		cout << "编号p没有祖先结点\n";
		return;
	}
	temp = temp->pra;
	while(temp->pra != NULL){
		temp = temp->pra;
		cout << "编号p的祖先结点的编号为：" << temp->idx << " ，数值为：" << temp->date << "\n";
	}
}

template<typename T>
void Tree<T>::Printun(int p){
	Node<T>* temp = new Node<T>;
	Node<T>* s = new Node<T>;
	stack<Node<T>*> t;
	bool flag = false;
	temp = findp(p,Root);
	if(temp == NULL)  return;  //没有p结点
	if(temp->son.size() == 0){
		cout << "编号p没有孙子结点\n";
		return;
	}
	for(int i = 0;i < temp->son.size();i++){
		t.push(temp->son[i]);
		while(!t.empty()){
			s = t.top();
			t.pop();
			for(int j = 0;j < s->son.size();j++){
				if(s->son[j]->son.size() != 0){
					flag = true;
					t.push(s.son[j]);
				}
				cout << "编号p的孙子结点的编号为：" << temp->idx << " ，数值为：" << temp->date << "\n";
			}
		}
	}

}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	Tree<int> a = new Tree<int>;
	return 0;
}