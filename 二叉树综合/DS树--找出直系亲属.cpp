#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	char data;
	node *left,*right;
	node(char a){
		left=NULL;
		right=NULL;
		data=a;
	}
	node(){
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
	void create(string a){
		root=new node(a[0]);
		root->left=new node(a[1]);
		root->right=new node(a[2]);
	}
	node* lookfor(node*&root,char a){
		if(root){
			if(root->data==a){
			return root;
		}else{
			node*i=lookfor(root->left,a);
			if(i)return i;
			node*j=lookfor(root->right,a);
			if(j)return j;
			return NULL;
		}
		}
		return NULL;
	}
	void link(string a){
		node*newroot=lookfor(root,a[0]);
		newroot->left=new node(a[1]);
		newroot->right=new node(a[2]);
	}
	int lookfor2(node*&root,char a,int i){
		if(root){
			if(root->data==a){
				return i;
			}
			int j=lookfor2(root->left,a,i+1);
			if(j!=-100)return j;
			int k=lookfor2(root->right,a,i+1);
			if(k!=-100)return k;
			if(i==0)return -1;
			else return -100;
		}
		return -100;
	}
	void output(char a,char b){
		char x,d;
		int flag;
		if(a>b){
			x=b;
			d=a;
			flag=0;
		}else{
			x=a;
			d=b;
			flag=1;
		}
		node*xiaonode=lookfor(root,x);
		int deep=lookfor2(xiaonode,d,0);
		if(deep==-1){
			cout<<"-"<<endl;
		}else if(deep==1){
			if(flag==0){
				cout<<"parent"<<endl;
			}else{
				cout<<"child"<<endl;
			}
		}else if(deep==2){
			if(flag){
				cout<<"grandchild"<<endl;
			}else{
				cout<<"grandparent"<<endl;
			}
		}else if(deep>=3){
			for(int i=3;i<=deep;i++){
				cout<<"great-";
			}
			if(flag){
				cout<<"grandchild"<<endl;
			}else{
				cout<<"grandparent"<<endl;
			}
		}
	}
};
int main(){
	int n,m;
	while(cin>>n>>m&&n&&m){
		tree t;
		string a,b;
		for(int i=0;i<n;i++){
			cin>>a;
			if(!i){
				t.create(a);
			}else{
				t.link(a);
			}
		}
		for(int i=0;i<m;i++){
			cin>>b;
			t.output(b[0],b[1]);
		}
	}
}
