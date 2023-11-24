#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node *left,*right;
};
class tree{
	public:
	node *root;
	int minn;
	node(){
		minn=9999999;
		root=NULL;
	}
	void create(){
		create(root);
	}
	void create(node *&root){
		create(root->left)
		int op;
		cin>>op;
		
	}
};
