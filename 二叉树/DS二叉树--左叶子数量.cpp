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
	int count;
	tree(){
		count=0;
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
	void bianlizuoye(){
		bianlizuoye(root); 
	}
	void bianlizuoye(node *a){
		if(a){
			if(a->left){
				if(!a->left->left&&!a->left->right){
					count++;
				}
			}
			bianlizuoye(a->left);
			bianlizuoye(a->right);
		}
	} 
	
};
int main(){
	int t;
	cin>>t;
	while(t--){

		tree t1;
		t1.create();
		t1.bianlizuoye();
		cout<<t1.count<<endl;
	}
}
