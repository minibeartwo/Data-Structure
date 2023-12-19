#include <bits/stdc++.h>
using namespace std;
int search(int *a,int x,int n){
	int index=0,l,r,mid;
	for(int i=0;i<n;i++){
		if(a[0]>a[i]){
			index=i;
			break;
		}
	}
	if(index==0)index=n-1;
	else if(x<a[index]||x>a[index-1])return -1;
	if(x>=a[0]){
		l=0,r=index;
		while(l<=r){
			mid=(l+r)/2;
			if(a[mid]==x){
				return mid;
			}else if(a[mid]>x){
				r=mid-1;
			}else if(a[mid]<x){
				l=mid+1;
			}
		}
		return -1;
	}else{
		l=index;
		r=n-1;
		while(l<=r){
			mid=(l+r)/2;
			if(a[mid]==x){
				return mid;
			}else if(a[mid]>x){
				r=mid-1;
			}else if(a[mid]<x){
				l=mid+1;
			}
		}
		return -1;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,*a;
		cin>>n;
		a=new int[n];
		for(int i=0;i<n;i++)cin>>a[i];
		int x;
		cin>>x;
		cout<<search(a,x,n)<<endl;
		delete []a;
	}
}
