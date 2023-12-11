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
		if(op=='#'){
			a=NULL;
		}else{
			a=new node(op);
			create(a->left);
			create(a->right);
		}
	}
	void bianli1(){
		bianli1(root);
	}
	void bianli1(node *a){
		if(a){
			cout<<a->data;
			bianli1(a->left);
			bianli1(a->right);
		}
	}
	void bianli2(){
		bianli2(root);
	}
	void bianli2(node *a){
		if(a){
			bianli2(a->left);
			cout<<a->data;
			bianli2(a->right);
		}
	}
	void bianli3(){
		bianli3(root);
	}
	void bianli3(node *a){
		if(a){
			bianli3(a->left);
			bianli3(a->right);
			cout<<a->data;
		}
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t1;
		t1.create();
		t1.bianli1();
		cout<<endl;
		t1.bianli2();
		cout<<endl;
		t1.bianli3();
		cout<<endl;
	}
}
