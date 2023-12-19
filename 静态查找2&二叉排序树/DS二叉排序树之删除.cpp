#include <bits/stdc++.h>
using namespace std;
class node{
	public:
		node *left,*right,*parent;
		int data;
		node(){
			parent=NULL;
			left=NULL;
			right=NULL;
		}
		node(int x){
			parent=NULL;
			left=NULL;
			right=NULL;
			data=x;
		}
}; 
class tree{
	public:
		node *root;
		tree(int x){
			root=new node(x);
		}
		void insert(int x){
			insert(x,root);
		}
		void insert(int x,node *&root){
			if(x>root->data&&root->right){
				insert(x,root->right);
			}else if(x<root->data&&root->left){
				insert(x,root->left);
			}else if(x>root->data&&!root->right){
				node *temp=new node(x);
				root->right=temp;
				temp->parent=root;
			}else if(x<root->data&&!root->left){
				node *temp=new node(x);
				root->left=temp;
				temp->parent=root;
			}
		}
		void zhongxubianli(){
			zhongxubianli(root);
		}
		void zhongxubianli(node *root){
			if(root){
				zhongxubianli(root->left);
				cout<<root->data<<" ";
				zhongxubianli(root->right);
			}
		}
		void del(int x){
			if(root){
				del(x,root);
			}
		}
		void del(int x,node *&root){
			if(x<root->data&&root->left){
				del(x,root->left);
			}else if(x>root->data&&root->right){
				del(x,root->right);
			}else if(x==root->data){
				if(!root->left&&!root->right){
					delete root;
					root=NULL;
				}else if(root->left&&!root->right){
					node *temp=root;
					root=root->left;
					delete temp;
				}else if(root->right&&!root->left){
					node *temp=root;
					root=root->right;
					delete temp;
				}else if(root->left&&root->right){
					node*temp=root->left;
					while(temp->right){
						temp=temp->right;
					}
					root->data=temp->data;
					if(root->left==temp){
						root->left=temp->left;
						return;
					}
					temp->parent->right=temp->left;
					delete temp;
				}
			}
		}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n;
		cin>>x;
		tree t(x);
		n--;
		while(n--){
			cin>>x;
			t.insert(x);
		}
		t.zhongxubianli();
		cout<<endl;
		cin>>n;
		while(n--){
			cin>>x;
			t.del(x);
			t.zhongxubianli();
			cout<<endl;
		}
	}
}
