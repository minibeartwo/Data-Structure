#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	char data;
	node *left,*right;
	node(char a){
		data=a;
		left=NULL;
		right=NULL;
	}
};
class tree{
	public:
	node *root;
	queue<node*>q1;
	queue<char>q2;
	tree(){
		root=NULL;
	}
	void create(){
		create(root);
	}
	void create(node *&a){
		char op;
		cin>>op;
		if(op=='0'){
			a=NULL;
		}else{
			a=new node(op);
			create(a->left);
			create(a->right);
		}
	}
	void xianxu(){
		q1.push(root);
		while(q1.size()){
			if(q1.front()->left){
				q1.push(q1.front()->left);
			}
			if(q1.front()->right){
				q1.push(q1.front()->right);
			}
			q2.push(q1.front()->data);
			q1.pop();
		}
		while(q2.size()){
			cout<<q2.front();
			q2.pop();
		}
		cout<<endl;
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t1;
		t1.create();
		t1.xianxu();
	}
}
