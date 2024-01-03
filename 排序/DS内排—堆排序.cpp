#include <bits/stdc++.h>
using namespace std;
void paixu(int *a,int n,int i){
	int j=2*i;
	while(j<=n){
		if(j<n&&a[j]>a[j+1])j++;
		if(a[i]>a[j]){
			swap(a[i],a[j]);
		}
		i=j;
		j*=2;
	}
} 
int main(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n/2;i>=1;i--){
		paixu(a,n,i);
	}
	cout<<n<<" ";
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0;i<n-1;i++){
		a[0]=a[1];
		a[1]=a[n-i];
		a[n-i]=a[0];
		paixu(a,n-1-i,1);
		cout<<n<<" ";
		for(int j=1;j<=n;j++)cout<<a[j]<<" ";
		cout<<endl;
	}
}
