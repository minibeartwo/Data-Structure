#include <bits/stdc++.h>
using namespace std;
int a[1100][1100],n,vis[1100];
int solve(){
	int now=-1;
	for(int i=0;i<n;i++){
		int flag=1;
		for(int j=0;j<n;j++){
			if(a[j][i]==1||vis[i]){
				flag=0;
				break;
			}
		}
		if(flag==1){
			now=i;
			vis[i]=1;
			break;
		}
	}
	for(int i=0;i<n;i++){
		a[now][i]=0;
	}
	return now;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)cin>>a[i][j];
		}
		for(int i=0;i<n;i++){
			cout<<solve()<<" ";
		}
		cout<<endl;
	}
}
