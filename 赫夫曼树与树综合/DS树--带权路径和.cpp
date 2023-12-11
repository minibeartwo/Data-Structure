#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	char name;
	int r;
	node *left,*right;
	node(char a){
		left=NULL;
		right=NULL;
		name=a;
	}
};
class tree{
	public:
	node *root;
	queue<int>w;
	int sum;
	tree(){
		root=NULL;
		sum=0;
	}
	void create(){
		create(root,0);
	}
	void create(node *&a,int b){
		char op;
		cin>>op;
		if(op=='0'){
			a=NULL;
		}else{
			a=new node(op);
			a->r=b;
			create(a->left,b+1);
			create(a->right,b+1);
		}
	}
	void getsum(){
		int n;
		cin>>n;
		while(n--){
			int x;
			cin>>x;
			w.push(x);
		}
	}
	void preorder(){
		preorder(root);
		cout<<sum<<endl;
	}
	void preorder(node *a){
		if(a){
			if(!a->left&&!a->right){
				sum+=a->r*w.front();
				w.pop();
			}
			preorder(a->left);
			preorder(a->right);
		}
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t1;
		t1.create();
		t1.getsum();
		t1.preorder();
	}
}
