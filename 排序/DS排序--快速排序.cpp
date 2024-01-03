#include <bits/stdc++.h>
using namespace std;
int n,*a;
void qsort(int b,int c){
	if(b>=c)return;
	int temp=a[b];
	int l=b,r=c;
	while(l<r){
		while(l<r&&temp<=a[r])r--;
		swap(a[l],a[r]);
		while(l<r&&temp>=a[l])l++;
		swap(a[l],a[r]);
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	qsort(b,r-1);
	qsort(r+1,c);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		a=new int[n];
		for(int i=0;i<n;i++)cin>>a[i];
		qsort(0,n-1);
		cout<<endl;
		delete a;
	}
}
