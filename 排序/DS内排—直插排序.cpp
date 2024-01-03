#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n]={0};
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++){
		if(a[i+1]<a[i]){
			for(int j=0;j<i+1;j++){
				if(a[j]>a[i+1])swap(a[j],a[i+1]);
			}
		}
		for(int i=0;i<n;i++)cout<<a[i]<<" ";
		cout<<endl;
	}
}
