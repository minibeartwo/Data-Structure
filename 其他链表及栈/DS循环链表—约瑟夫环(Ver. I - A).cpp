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
	node *head;
	int len;
	public:
		linklist(int n){
			len=n;
			head=new node;
			node *p=head;
			head->data=1;
			for(int i=1;i<n;i++){
				node *x=new node;
				x->data=i+1;
				p->next=x;
				p=p->next;
			}
			p->next=head;
		}
		void del(node *x){
			node *p=x;
			while(p->next!=x){
				p=p->next;
			}
			p->next=x->next;
			len--;
			free(x);
		}
		void display(int s,int k){
			node *p=head;
			for(int i=1;i<s;i++){
				p=p->next;
			}
			while(len!=1){
				for(int i=1;i<k;i++){
					p=p->next;
				}
				cout<<p->data<<" ";
				node *q=p;
				p=p->next;
				del(q); 
			}
			cout<<p->data<<" "<<endl;
			del(p);
		}
};
int main(){
	int t,n,s,k;
	cin>>t;
	while(t--){
		cin>>n;
		linklist l(n);
		cin>>k>>s;
		l.display(s,k);
	}
}
