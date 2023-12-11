#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	char data;
	node *next;
	node(){
		next=NULL;
	}
};
class zhan{
	public:
	node *top;
	int len;
	zhan(){
		top=NULL;
		len=0;
	}
	void ruzhan(int x){
		node *p=new node;
		p->data=x;
		p->next=top;
		top=p;
		len++;
	}
	void chuzhan(){
		if(top){
			node *p=top;
			cout<<top->data;
			top=top->next;
			free(p);
			len--;
		}
	}
	int getlen(){
		return len;
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		zhan l;
		for(int i=0;i<a.size();i++){
			l.ruzhan(a[i]);
		}
		while(l.getlen()){
			l.chuzhan();
		}
		cout<<endl;
	}
}
