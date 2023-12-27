#include <bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node *next;
};
node *haxi[11];
void add(int x){
	node *temp=new node;
	temp->data=x;
	temp->next=haxi[x%11];
	haxi[x%11]=temp;
}
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<11;i++)haxi[i]=NULL;
		while(n--){
			int x;
			cin>>x;
			add(x);
		}
		cin>>n;
		while(n--){
			int x,num=1;
			cin>>x;
			node *temp=haxi[x%11];
			while(temp){
				if(temp->data==x)break;
				temp=temp->next;
				num++;
			}
			if(temp)cout<<x%11<<" "<<num<<endl;
			else{
				cout<<"error"<<endl;
				add(x);
			}
		}
	}
}
