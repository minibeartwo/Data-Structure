#include <bits/stdc++.h>
using namespace std;
void walk(int x,int y,int m,int n,int **a){
	a[x][y]=1;
	if(y+1<n+2&&a[x][y+1]==0)walk(x,y+1,m,n,a);
	if(x+1<m+2&&a[x+1][y]==0)walk(x+1,y,m,n,a);
	if(x-1>=0&&a[x-1][y]==0)walk(x-1,y,m,n,a);
	if(y-1>=0&&a[x][y-1]==0)walk(x,y-1,m,n,a);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>m>>n;
		int **a=new int*[m+2];
		for(int i=0;i<m+2;i++){
			a[i]=new int[n+2];
		}
		for(int i=0;i<m+2;i++){
			for(int j=0;j<n+2;j++)a[i][j]=0;
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++)cin>>a[i][j];
		}
		walk(0,0,m,n,a);
		int sum=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0)sum++;
			}
		}
		cout<<sum<<endl;
	}
}
