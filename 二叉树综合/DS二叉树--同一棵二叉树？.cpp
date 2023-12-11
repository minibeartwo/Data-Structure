#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	node *left,*right;
	char data;
};
class tree{
	public:
		node *root;
		string a,b;
		int len,i=-1;
		tree(){
			cin>>a>>b;
			len=a.size();
		}
		void create(){
			create(root);
		}
		void create(node*&x){
			if(i==b.size())return;
			i++;
			if(b[i]=='#'){
				x=new node;
				x->data='#';
			    x->left=NULL;
			    x->right=NULL;
			}else{
				x=new node;
				x->data=b[i];
				create(x->left);
				create(x->right);
			}
		}
		void bijiao(){
			node *p;
			queue<node*>q;
			q.push(root);
			for(int i=0;i<len;i++){
				p=q.front();
				q.pop();
				if(p){
					if(p->data!=a[i]){
						cout<<"NO"<<endl;
						return;
					}
					q.push(p->left);
					q.push(p->right);
				}
			}
			cout<<"YES"<<endl;
		}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t1;
		t1.create();
		t1.bijiao();
	}
}
