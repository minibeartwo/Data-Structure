#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	char data;
	int w;
	node *left,*right;
	node(){
		left=NULL;
		right=NULL;
	}
};
class tree{
	public:
	string a;
	int pos,len,ans;
	node *root;
	queue<int>q;
	tree(){
		cin>>a;
		len=a.size();
		pos=0;
		ans=0;
		root=new node;
		int n;
		cin>>n;
		while(n--){
			int x;
			cin>>x;
			q.push(x);
		}
		create();
	}
	void create(){
		create(root);
	}
	void create(node*&root){
		if(pos>=len)return;
		if(a[pos]=='0'){
			root=NULL;
			pos++;
		}else{
			root->data=a[pos++];
			root->left=new node;
			root->right=new node;
			create(root->left);
			create(root->right);
		}
	}
	void yuchuli(){
		yuchuli(root);
	}
	void yuchuli(node*&root){
		if(!root)return;
		if(root){
			root->w=q.front();
			q.pop();
		}
		yuchuli(root->left);
		yuchuli(root->right);
	}
	void findans(){
		findans(root,0);
	}
	void findans(node*root,int temp){
		if(root==NULL)return;
		if(root){
			temp+=root->w;
			ans=max(ans,temp);
			findans(root->left,temp);
			findans(root->right,temp);
		}
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t1;
		t1.yuchuli();
		t1.findans();
		cout<<t1.ans<<endl;
	} 
}
