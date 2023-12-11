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
	void create(node*&a){
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
	void mirror(){
		mirror(root);
	}
	void mirror(node *a){
		if(a){
			mirror(a->left);
			mirror(a->right);
			swap(a->left,a->right);
		}
	}
	void bianli1(){
		bianli1(root);
	}
	void bianli1(node *a){
		if(a==NULL)return;
		if(a){
			cout<<a->data<<" ";
			bianli1(a->left);
			bianli1(a->right);
		}
	}
	void bianli2(){
		bianli2(root);
	}
	void bianli2(node *a){
		if(!a)return;
		if(a){
			bianli2(a->left);
			cout<<a->data<<" ";
			bianli2(a->right);
		}
	}
	void bianli3(){
		bianli3(root);
	}
	void bianli3(node *a){
		if(a==NULL)return;
		if(a){
			bianli3(a->left);
			bianli3(a->right);
			cout<<a->data<<" ";
		}
	}
	void bianli4(){
		bianli4(root);
	}
	void bianli4(node *a){
		queue<node *>q;
		q.push(a);
		if(a==NULL)return;
		while(q.size()){
			node *p=q.front();
			q.pop();
			cout<<p->data<<" ";
			if(p->left){
				q.push(p->left);
			}
			if(p->right){
				q.push(p->right);
			}
		}
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t;
		t.create();
		t.mirror();
		if(t.root==NULL){
			cout<<"NULL"<<endl;
			cout<<"NULL"<<endl;
			cout<<"NULL"<<endl;
			cout<<"NULL"<<endl;
			continue;
		}
		t.bianli1();
		cout<<endl;
		t.bianli2();
		cout<<endl;
		t.bianli3();
		cout<<endl;
		t.bianli4();
		cout<<endl;
	}
}
