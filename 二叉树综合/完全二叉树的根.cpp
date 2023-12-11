#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,t;
	cin>>n;
	t=n*(n-1)*(n-2);
	int a[20]={0},b[20]={0};
	for(int i=0;i<t;i++){
		int c,d,e,f;
		cin>>c>>d>>e>>f;
		if(f){
			a[e]++;
			b[e]=d;
		}
	}
	int temp=0,flag=1;
	for(int i=1;i<=n;i++){
		if(a[temp]<a[i]){
			temp=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]==temp){
			flag=0;
		}
	}
	if(flag){
		cout<<temp;
	}
}
