#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	int index;
	string name;
	node *next;
	node(){
		next=NULL;
	}
}; 
class ma{
	public:
	node *a;
	int n,m;
	ma(){
		cin>>n>>m;
		a=new node[n];
		for(int i=0;i<n;i++){
			a[i].index=i;
			cin>>a[i].name;
		}
	}
	void create(){
		string b,c;
		int d=0,e=0;
		for(int i=0;i<m;i++){
			cin>>b>>c;
			for(int j=0;j<n;j++){
				if(a[j].name==b){
					d=j;
				}else if(a[j].name==c){
					e=j;
				}
			}
			node *temp=new node;
			temp->index=e;
			if(a[d].next){
				node *t=a[d].next;
				while(t->next){
					t=t->next;
				}
				t->next=temp;
			}else if(a[d].next==NULL){
				a[d].next=temp;
			}
		}
		for(int i=0;i<n;i++){
			cout<<a[i].index<<" "<<a[i].name<<"-";
			node *t=a[i].next;
			while(t){
				cout<<t->index<<"-";
				t=t->next;
			}
			cout<<"^"<<endl;
		}
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		ma m;
		m.create();
	}
}
