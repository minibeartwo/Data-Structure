#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	char data;
	int w,l,r,p;
	node(){
		w=0;
		l=0;
		r=0;
		p=0;
	}
}; 
class tree{
	public:
		node *root;
		string a;
		int num,len;
		tree(){
			string s;
			cin>>s;
			a+=s[0];
			for(int i=0;i<s.size();i++){
				int flag=1;
				for(int j=0;j<a.size();j++){
					if(s[i]==a[j]){
						flag=0;
						break;
					}
				}
				if(flag){
					a+=s[i];
				}	
			}
			num=a.size();
			len=2*num-1;
			root=new node[len+1];
			for(int i=1;i<=num;i++){
				root[i].data=a[i-1];
				for(int j=0;j<s.size();j++){
					if(s[j]==root[i].data){
						root[i].w++;
					}
				}
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
			b=c=0;
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
		void show(){
			int changdu=0;
			for(int i=num+1;i<=len;i++){
				changdu+=root[i].w;
			}
			cout<<changdu<<endl;
		}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t1;
		t1.show();
	}
}
