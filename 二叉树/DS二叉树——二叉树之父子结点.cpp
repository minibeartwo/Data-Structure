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
	void bianliyezi(){
		bianliyezi(root);
	}
	void bianliyezi(node *a){
		if(a){
			if(!a->left&&!a->right){
				cout<<a->data<<" ";
			}
			bianliyezi(a->left);
			bianliyezi(a->right);
		}
	}
	void bianlifuqin(){
		bianlifuqin(root);
	}
	void bianlifuqin(node *a){
		if(a){
		if(a->left){
			if(!a->left->left&&!a->left->right){
				cout<<a->data<<" ";
			}
		}
		bianlifuqin(a->left);
		if(a->right){
			if(!a->right->left&&!a->right->right){
				cout<<a->data<<" ";
			}
		}
		bianlifuqin(a->right);
		}
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t1;
		t1.create();
		t1.bianliyezi();
		cout<<endl;
		t1.bianlifuqin();
		cout<<endl;
	}
}
