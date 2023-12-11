#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	int w,l,r,p;
	char data;
}; 
class tree{
	public:
		string *code;
		node *root;
		int num,len;
		tree(int n,int *wt,char *dt){
			num=n;
			len=2*n-1;
			code=new string[len+1];
			root=new node[2*n];
			for(int i=1;i<=n;i++){
				root[i].w=wt[i];
				root[i].data=dt[i];
			}
			for(int i=1;i<=len;i++){
				if(i>n){
					root[i].w=0;
					root[i].data='0';
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
				root[i].w=root[s1].w+root[s2].w;
				root[i].l=s1;
				root[i].r=s2;
			}
		}
		void select(int a,int &b,int &c){
			int w1=9999999,w2=9999999;
			b=0;
			c=0;
			for(int i=1;i<=a;i++){
				if(w1>root[i].w&&root[i].p==0){
					w2=w1;
					c=b;
					w1=root[i].w;
					b=i;
				}else if(w2>root[i].w&&root[i].p==0){
					w2=root[i].w;
					c=i;
				}
			} 
		}
		int decode(const string codestr,char textstr[]){
			int c=len,k=0;
			char ch;
			for(int i=0;i<codestr.size();i++){
				ch=codestr[i];
				if(ch=='0'){
					c=root[c].l;
				}else if(ch=='1'){
					c=root[c].r;
				}else if(ch!='0'&&ch!='1'){
					return 0;
				}
				if(root[c].l==0&&root[c].r==0){
					textstr[k++]=root[c].data;
					c=len;
				}else{
					ch='\0';
				}
			}
			if(ch=='\0'){
				return 0;
			}else{
				textstr[k]='\0';
				return 1;
			}
		}
};
int main(){
	int t,wt[800];
	char dt[800],textstr[800];
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>wt[i];
		}
		int i;
		for(i=1;i<=n;i++){
			cin>>dt[i];
		}
		tree t1(n,wt,dt);
		cin>>n;
		while(n--){
			string a;
			cin>>a;
			if(t1.decode(a,textstr)==1){
				cout<<textstr<<endl;
			}else{
				cout<<"error"<<endl;
			}
		} 
	}
	
}

