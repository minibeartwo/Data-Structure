#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node *next;
	node(){
		next=NULL;
	}
};
node *haxi[11];
void insert(int x){
	node *p=new node;
	p->data=x;
	if(!haxi[x%11]){
		haxi[x%11]=p;
	}else{
		node *temp=haxi[x%11];
		while(temp->next){
			temp=temp->next;
		}
		temp->next=p;
	}
}
void find(int x){
	int count=1;
	node *p=haxi[x%11];
	while(p){
		if(p->data==x)break;
		p=p->next;
		count++;
	}
	if(p){
		cout<<x%11<<" "<<count<<endl;
	}else{
		cout<<"error"<<endl;
		insert(x);
	}
}
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<11;i++)haxi[i]=NULL;
		while(n--){
			int x;
			cin>>x;
			insert(x);
		}
		int m;
		cin>>m;
		while(m--){
			int x;
			cin>>x;
			find(x);
		}
	}
}
