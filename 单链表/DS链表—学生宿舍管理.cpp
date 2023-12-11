#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	string name;
	int data;
	node *next;
	node(){
		next=NULL;
	}
};
class linklist{
	public:
	int len;
	node *head;

	linklist(){
		len=0;
		head=new node;
	}
	~linklist(){
		node *p=head;
		node *q;
		while(p){
			q=p;
			p=p->next;
			delete q;
		}
		len=0;
		head=NULL;
	}
};
int main(){
	linklist m,n;
	node *a=m.head;
	node *b=n.head;
	node *p;
	int n1,n2;
	cin>>n1; 
	int i,j;
	for(i=0;i<n1;i++){
		p=new node;
		cin>>p->name>>p->data;
		a->next=p;
		a=a->next; 
	}
	node *r;
	for(i=101;i<=120;i++){
		int x=0;
		r=m.head;
		for(j=0;j<n1;j++){
			r=r->next;
			if(r->data==i){
				x=1;
				break;
			}
		}
		if(x==0){
			node *t=new node;
			t->data=i;
			b->next=t;
			b=b->next;
		}
	}
	string c;
	cin>>n2;
	while(n2--){
		cin>>c;
		if(c=="assign"){
			b=n.head;
			p=b->next;
			b->next=p->next;
			cin>>p->name;
			a=m.head;
			while(a){
				if((a->data<p->data||a==m.head)&&(a->next->data>p->data||a->next==NULL)){
					p->next=a->next;
					a->next=p;
					break;
				}else{
					a=a->next;
				}
			}
		}else if(c=="return"){
			int temp;
			cin>>temp;
			a=m.head;
			while(a){
				b=a->next;
				if(b->data==temp){
					a->next=b->next;
					p=n.head;
					while(p->next){
						p=p->next;
					}
					p->next=b;
					b->next=NULL;
					break;
				}else{
					a=a->next;
				}
			}
		}else if(c=="display_free"){
			p=n.head->next;
			while(p){
				cout<<p->data;
				if(p->next){
					cout<<"-";
				}
				p=p->next;
			}
			cout<<endl;
		}else if(c=="display_used"){
			p=m.head->next;
			while(p){
				cout<<p->name<<"("<<p->data<<")";
				if(p->next){
					cout<<"-";
				}
				p=p->next;
			}
			cout<<endl;
		}
	}
}
