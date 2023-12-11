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
		int insert(int i,int item){
			node *p=head,*q=new node;
			if(i<=0||i>len+1){
				cout<<"error"<<endl;
				return 0;
			}
			i--;
			while(i--){
				p=p->next;
			}
			q->data=item;
			q->next=p->next;
			p->next=q;
			len++;
			return 1;
		}
		void display(){
			node *p=head->next;
			while(p){
				cout<<p->data<<" ";
				p=p->next;
			}
			cout<<endl;
		}
		int del(int i){
			if(i<=0||i>len){
				cout<<"error"<<endl;
				return 0;
			}
			node *p=head;
			i--;
			while(i--){
				p=p->next;
			}
			node *q=p->next;
			p->next=q->next;
			len--;
			return 1;
		}
		void find(int i){
			if(i<=0||i>len){
				cout<<"error"<<endl;
				return;
			}
			node *p=head;
			while(i--){
			p=p->next;
			}
			cout<<p->data<<endl;
		}
		void swap(int a,int b){
			if(a<=0||a>len||b<=0||b>len){
				cout<<"error"<<endl;
				return;
			}
			node *p=head;
			while(a--){
				p=p->next;
			}
			int temp=p->data;
			node *q=head;
			while(b--){
				q=q->next;
			}
			p->data=q->data;
			q->data=temp;
			display();
		}
};
int main(){
	int n;
	cin>>n;
	linklist l;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		l.insert(i,x);
	}
	l.display();
	int a,b;
	cin>>a>>b;
	l.swap(a,b);
	cin>>a>>b;
	l.swap(a,b);
}
