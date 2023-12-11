#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	char data;
	int r;
	node *left,*right;
	node(char a){
		data=a;
		left=NULL;
		right=NULL;
		r=0;
	}
};
class tree{
	public:
	int ans;
	node *root;
	queue<node*>q1;
	queue<char>q2;
	tree(){
		ans=0;
		root=NULL;
	}
	void create(){
		create(root,1);
	}
	void create(node *&a,int b){
		char op;
		cin>>op;
		if(op=='0'){
			a=NULL;
		}else{
			ans=max(ans,b);
			a=new node(op);
			a->r=b;
			create(a->left,b+1);
			create(a->right,b+1);
		}
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t1;
		t1.create();
		cout<<t1.ans<<endl;
	}
}

