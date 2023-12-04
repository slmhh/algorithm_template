#include<bits/stdc++.h>
#define debug(x) cout << "#x" << x << endl;
#define all(x) (x).begin(),(x).end()
using namespace std;

int nums[10] = {0,3,9,4,6,8,7,5,2,1};

//节点
struct node{
	int val;
	node *l,*r;
};

//插入x
node *insert(node *p,int x){
	if(p == NULL){
		node *q = new node;
		q->val = x;
		q->l = q->r = NULL;
		return q;
	}
	else{
		if(x < p->val) p->l = insert(p->l,x);
		else p->r = insert(p->r,x);
		return p;
	}
}

//查找数值x
bool find(node *p,int x){
	if(p == NULL) return false;
	else if(x == p->val) return true;
	else if(x < p->val) return find(p->l,x);
	else return find(p->r,x);
}

//删除数值x
node *remove(node *p,int x){
	if(p == NULL) return NULL;
	else if(x < p->val) p->l = remove(p->l,x);
	else if(x > p->val) p->r = remove(p->r,x);
	else if(p->l == NULL){
		node *q = p->l;
		delete p;
		return q;
	}
	else if(p->l->r == NULL){
		node *q = p->l;
		delete p;
		return q;
	}
	else{
		node *q;
		for(q = p->l;q->r->r !=NULL;q = q->r);
		node *temp = q->r;
		q->r = temp->l;
		temp->l = p->l;
		temp->r = p->r;
		delete p;
		return temp;
	}
	return p;	
}

int main(){
	node *tree = NULL;
	for(int i = 0;i < 10;i++){
		tree = insert(tree,nums[i]);
	}
	
	if(find(tree,5)) puts("YES");
	else puts("NO");
	
	tree = remove(tree,5);
	if(find(tree,5)) puts("YES");
	else puts("NO");
	
    return 0;
}
