#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	node *next,*pre;
	char data;
		node(){
			next=NULL;
			pre=NULL;
		}
};
class linklist{
	node *head;
	int len;
	public:
		linklist(int n){
			head=new node;
			node *p=head;
			string a;
			cin>>a;
			for(int i=0;i<n;i++){
				node *q=new node;
				q->data=a[i];
				p->next=q;
				q->pre=p;
				p=q;
			}
			len=n;
		}
		void test(int n){
			int pos;
			char op;
			while(n--){
				cin>>pos>>op;
				int temp=pos;
				node *p=head;
				while(temp--){
					p=p->next;
				}
				node *q=new node;
				q->data=op;
				q->next=p->next;
				q->pre=p;
				if(p->next){
					p->next->pre=q;
				}
				p->next=q;
				len++;
				while(1){
					while(p&&p->data==op){
						p=p->pre;
					}
					while(q&&q->data==op){
						q=q->next;
					}
					int num=0;
					node *r=p;
					while(r&&r!=q){
						num++;
						r=r->next;
					}
					if(num>=4){
						p->next=q;
						if(q){
							q->pre=p; 
						}
						if(p!=head){
							op=p->data;
						}else if(q){
							op=q->data;
						}
						len-=num-1;
					}else break;
				}
				if(len==0){
					cout<<"-"<<endl;
				}else{
					p=head;
					while(p->next){
						p=p->next;
						cout<<p->data;
					}
					cout<<endl;
				}
			}
		}
};
int main(){
	int t;
	cin>>t;
	linklist l(t);
	cin>>t;
	l.test(t);
}
