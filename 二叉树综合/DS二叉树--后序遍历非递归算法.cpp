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
		if(op=='0'){
			a=NULL;
		}else{
			a=new node(op);
			create(a->left);
			create(a->right);
		}
	}
	void bianli(){
		bianli(root);
	}
	void bianli(node *a){
		stack<node *>s1;
		stack<int>s2;
		node *p=a;
		do{
			while(p){
				s1.push(p);
				s2.push(0);
				p=p->left;
				if(s1.empty())break;
			}
			if(!p){
				if(s2.top()==0){
					s2.top()=1;
					p=s1.top()->right;
				}else if(s2.top()){
					p=s1.top();
					s1.pop();
					s2.pop();
					cout<<p->data;
					p=NULL;
				}
			}
		}while(s1.size());
		cout<<endl;
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t;
		t.create();
		t.bianli();
	}
}
