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
			data=x;
			left=NULL;
			right=NULL;
		}
};
class tree{
	public:
		int count;
		node *root;
		tree(int x){
			count=0;
			root=new node(x);
		}
		void insert(int x){
			insert(x,root);
		}
		void insert(int x,node *&root){
			if(root->data<x&&root->right){
				insert(x,root->right);
			}else if(root->data>x&&root->left){
				insert(x,root->left);
			}else if(root->data<x&&!root->right){
				node *temp=new node(x);
				root->right=temp;
			}else if(root->data>x&&!root->left){
				node *temp=new node(x);
				root->left=temp;
			}
		}
		void zhongxubianli(){
			zhongxubianli(root);
			cout<<endl;
		}
		void zhongxubianli(node *root){
			if(root){
				zhongxubianli(root->left);
				cout<<root->data<<" ";
				zhongxubianli(root->right);
			}
		}
		void find(int x){
			count=0;
			if(find(x,root)){
				cout<<count<<endl;
			}else{
				cout<<-1<<endl;
			}
		}
		bool find(int x,node *root){
			if(x>root->data&&root->right){
				count++;
				return find(x,root->right);
			}else if(x<root->data&&root->left){
				count++;
				return find(x,root->left);
			}else if(x==root->data){
				count++;
				return true;
			}
			count++;
			return false;
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
		cin>>n;
		while(n--){
			int x;
			cin>>x;
			t.insert(x);
			t.zhongxubianli();
		}
	}
}
