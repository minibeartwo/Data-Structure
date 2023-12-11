#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(i==0){
			cout<<a[i];
		}else{
			cout<<" "<<a[i];
		}
	}
	cout<<endl; 
	int op,x;
	cin>>op>>x;
	if(op==0){
		while(x--){
			int temp=a[0];
			for(int i=0;i<n-1;i++){
				a[i]=a[i+1];
			}
			a[n-1]=temp;
		}
		for(int i=0;i<n;i++){
		if(i==0){
			cout<<a[i];
		}else{
			cout<<" "<<a[i];
		}
	}
	cout<<endl;
	}else{
		while(x--){
			int temp=a[n-1];
			for(int i=n-1;i>=1;i--){
				a[i]=a[i-1];
			}
			a[0]=temp;
		}
		for(int i=0;i<n;i++){
		if(i==0){
			cout<<a[i];
		}else{
			cout<<" "<<a[i];
		}
	}
	cout<<endl;
	}
	cin>>op>>x;
	if(op==0){
		while(x--){
			int temp=a[0];
			for(int i=0;i<n-1;i++){
				a[i]=a[i+1];
			}
			a[n-1]=temp;
		}
		for(int i=0;i<n;i++){
		if(i==0){
			cout<<a[i];
		}else{
			cout<<" "<<a[i];
		}
	}
	}else{
		while(x--){
			int temp=a[n-1];
			for(int i=n-1;i>=1;i--){
				a[i]=a[i-1];
			}
			a[0]=temp;
		}
		for(int i=0;i<n;i++){
		if(i==0){
			cout<<a[i];
		}else{
			cout<<" "<<a[i];
		}
	}
	}
}
