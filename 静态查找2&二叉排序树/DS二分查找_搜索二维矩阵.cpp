#include <bits/stdc++.h>
using namespace std;
int a[110][110];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cin>>a[i][j];
	}
	int t;
	cin>>t;
	while(t--){
		int i,x,j;
		cin>>x;
		for(i=0;i<n;i++){
			if(a[i][0]>=x)break;
		}
		if(i==0&&a[i][0]>x){
			cout<<"false"<<endl;
			continue;
		}
		for(j=0;j<n;j++){
			if(a[i-1][j]==x){
				break;
			}
		}
		if(a[i-1][j]==x)cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}
}
