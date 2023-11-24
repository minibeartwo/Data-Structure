#include <bits/stdc++.h>
using namespace std;
class node{
	public:
		int w,l,r,p;
};
class tree{
	public:
	node *root;
	string *code;
	int num,len;
	tree(int n,int *wt){
		num=n;
		len=2*n-1;
		root=new node[len+1];
		code=new string[n+1];
		for(int i=1;i<=n;i++){
			root[i].w=wt[i];
		}
		for(int i=1;i<=len;i++){
			if(i>n){
				root[i].w=0;
			}
			root[i].l=0;
			root[i].r=0;
			root[i].p=0;
		}
		create();
	}
	void create(){
		int s1,s2;
		for(int i=num+1;i<=len;i++){
			select(i-1,s1,s2);
			root[s1].p=i;
			root[s2].p=i;
			root[i].l=s1;
			root[i].r=s2;
			root[i].w=root[s1].w+root[s2].w;
		}
	}
	void select(int a,int &b,int &c){
		int w1=999,w2=999;
		b=c=0;
		for(int i=1;i<=a;i++){
			if(root[i].w<w1&&root[i].p==0){
				w2=w1;
				c=b;
				w1=root[i].w;
				b=i;
			}else if(root[i].w<w2&&!root[i].p){
				w2=root[i].w;
				c=i;
			}
		}
	}
	void coding(){
		for(int i=1;i<=num;i++){
			int f=root[i].p;
			int c=i;
			string cd;
			while(f){
				if(root[f].l==c){
					cd="0"+cd;
				}else if(root[f].r==c){
					cd="1"+cd;
				}
				c=f;
				f=root[f].p;
			}
			code[i]=cd;
		}
	}
};
int main(){
	int t,wt[800];
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>wt[i];
		tree t1(n,wt);
		t1.coding();
		for(int i=1;i<=n;i++){
			cout<<t1.root[i].w<<"-"<<t1.code[i]<<endl;
		}
	}
}
