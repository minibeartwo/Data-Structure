#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1]={0};
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int d=n/2;d>=1;d/=2){
			for(int i=d+1;i<=n;i++){
				a[0]=a[i];
				int j=i-d;
				while(j>0&&a[0]>a[j]){
					swap(a[j],a[d+j]);
					j=j-d;
				}
				a[j+d]=a[0];
			}
			for(int i=1;i<=n;i++)cout<<a[i]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
}
