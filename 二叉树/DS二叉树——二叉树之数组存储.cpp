#include <bits/stdc++.h>
using namespace std;
void print(int k,int n,int *a){
	if(k<n&&a[k]){
		cout<<a[k]<<" ";
		print(k*2+1,n,a);
	    print(k*2+2,n,a);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		print(0,n,a);
		cout<<endl;
	}
}
