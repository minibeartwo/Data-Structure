#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	node *left,*right;
	char data;
	node(){
		left=NULL;
		right=NULL;
	}
}; 
class tree{
	public:
	node *root;
	string a;
	int pos,len;
	tree(){
		cin>>a;
		pos=0;
		root=new node;
		len=a.size();
	}
	void create(){
		create(root);
	}
	void create(node*&root){
		if(pos>=len)return;
		if(a[pos]=='#'){
			pos++;
			root=NULL;
			return;
		}
		root->data=a[pos++];
		root->left=new node;
		root->right=new node; 
		create(root->left);
		create(root->right);
	}
	void getdepth(node *root,int h,int &a1,char &b){
		if(!root)return;
		if(h>a1){
			a1=h;
			b=root->data;
		}else if(h==a1){
			b=min(b,root->data);
		}
		getdepth(root->left,h+1,a1,b);
		getdepth(root->right,h+1,a1,b);
	}
	void askmaxn(node *root,int &a1,string &s){
		if(root==NULL)return;
		if(root->left==NULL&&root->right==NULL)return;
		int l=0,r=0;
		char l2=root->data,r2=root->data;
		if(root->left){
			getdepth(root->left,1,l,l2);
		}
		if(root->right){
			getdepth(root->right,1,r,r2);
		}
		string temp;
		temp+=min(l2,r2);
		temp+=max(l2,r2);
		int dis=l+r;
		if(dis>a1){
			a1=dis;
			s=temp;
		}else if(dis==a1){
			if(temp<s){
				s=temp;
			}
		}
		askmaxn(root->left,a1,s);
		askmaxn(root->right,a1,s);
	}
	void output(){
		int ans=0;
		string s;
		askmaxn(root,ans,s);
		cout<<ans<<":";
		if(ans){
			cout<<s[0]<<" "<<s[1];
		}
		cout<<endl;
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t1;
		t1.create();
		t1.output();
	}
}
