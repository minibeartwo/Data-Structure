#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node *next;
	node *pre;
	node(){
		next=NULL;
		pre=NULL;
	}
}; 
class linklist{
	public:
		node *head;
		int len;
		linklist(){
			len=0;
			head=new node;
		}
		~linklist(){
			node *p=head,*q;
			while(p){
				q=p;
				p=p->next;
				delete q;
			}
			len=0;
			head=NULL;
		}
		void insert(int item){
			node *pre=NULL,*cur=NULL,*now=NULL;
			cur=head;
			now=new node;
			now->data=item;
			now->next=NULL;
			while(cur->next!=NULL){
				pre=cur;
				cur=cur->next;
			}
			if(cur==head){
				cur->next=now;
			}else{
				cur->next=now;
				now->pre=cur;
			}
			len++;
		}
		void find(int i){
			node *cur;
			cur=head->next;
			while(cur){
				if(cur->data==i)break;
				cur=cur->next;
			}
			if(cur->pre!=NULL){
				cout<<cur->pre->data;
			}
			if(cur->next!=NULL){
				if(cur->pre){
					cout<<" ";
				}
				cout<<cur->next->data;
			}
			cout<<endl;
		}
};
int main(){
	int n,m;
	cin>>n>>m;
	linklist l;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		l.insert(x);
	}
	while(m--){
		int x;
		cin>>x;
		l.find(x);
	}
}
