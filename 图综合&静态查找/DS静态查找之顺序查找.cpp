#include <bits/stdc++.h>
using namespace std;
void search(int *a,int key,int n){
	a[0]=key;
	int i;
	for(i=n;a[i]!=key;i--);
	if(i==0)cout<<"error"<<endl;
	else cout<<i<<endl;
}
int main(){
	int n;
		while(cin>>n){
		int *a=new int[n+1];
		for(int i=1;i<=n;i++)cin>>a[i];
		int m;
		cin>>m;
		while(m--){
			int key;
			cin>>key;
			search(a,key,n);
		}
		delete a;	
		}
		
}
