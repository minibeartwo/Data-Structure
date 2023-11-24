#include <bits/stdc++.h>
using namespace std;
int *m,*l,len,ans;
class node{
	public:
	node *left,*right;
	int data;
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
	void create(){
		root=create(m,l,len);
	}
	node*create(int *mid,int *last,int n){
		if(n==0)return NULL;
		node*t=new node;
		int i;
		for(i=0;mid[i]!=last[n-1];i++);
		t->data=last[n-1];
		t->left=create(mid,last,i);
		t->right=create(mid+i+1,last+i,n-1-i);
		return t;
	}
	void getmin(){
		getmin(root);
	}
	void getmin(node*a){
		if(a){
			if(!a->left&&!a->right){
				ans=min(ans,a->data);
			}
			getmin(a->left);
			getmin(a->right);
		}
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		ans=9999999;
		cin>>len;
		m=new int[len];
		l=new int[len];
		for(int i=0;i<len;i++)cin>>m[i];
		for(int i=0;i<len;i++)cin>>l[i];
		tree t1;
		t1.create();
		t1.getmin();
		cout<<ans<<endl;
	}
}
