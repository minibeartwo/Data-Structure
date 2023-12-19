#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node *left,*right;
	node(){
		left=NULL;
		right=NULL;
	}
	node(int x){
		left=NULL;
		right=NULL;
		data=x;
	}
};
class tree{
	public:
	int *a,n,flag;
	node *root;
	queue<node*>q;
	tree(int x){
		flag=1;
		n=x;
		a=new int[n];
		for(int i=0;i<n;i++)cin>>a[i];
		create();
	}
	void bianli(){
		bianli(root);
	}
	void bianli(node *x){
		if(x){
			cout<<x->data<<" ";
			bianli(x->left);
			bianli(x->right);
		}
	}
	void create(){
		int k=0;
		if(a[k]!=-1){
			root=new node(a[k++]);
			q.push(root);
		}
		while(q.size()&&k<n){
			node *s=q.front();
			if(a[k]!=-1&&k<n){
				node *temp=new node(a[k++]);
				s->left=temp;
				q.push(temp);
			}
			if(a[k]!=-1&&k<n){
				node *temp=new node(a[k++]);
				s->right=temp;
				q.push(temp);
			}
			q.pop();
		}
	}
	bool check(){
		check(root);
		if(flag){
			return true;
		}else{
			return false;
		}
	}
	void check(node *x){
		if(x){
			if(x->left&&x->left->data>x->data){
				flag=0;
				return;
			}
			if(x->right&&x->right->data<x->data){
				flag=0;
				return;
			}
			check(x->left);
		    check(x->right);
		}
		}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		tree t(n);
		if(t.check()){
			cout<<"true"<<endl;
		}else{
			cout<<"false"<<endl;
		}
	}
}
