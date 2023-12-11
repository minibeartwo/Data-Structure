#include <bits/stdc++.h>
using namespace std;
class ma{
	public:
	int **a,*vis,n;
	ma(){
		cin>>n;
		vis=new int[n];
		for(int i=0;i<n;i++)vis[i]=0;
		a=new int*[n];
		for(int i=0;i<n;i++)a[i]=new int[n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)cin>>a[i][j];
		}
		for(int i=0;i<n;i++){
			if(!vis[i])dfs(i);
		}
		cout<<endl;
	}
	void dfs(int x){
		cout<<x<<" ";
		vis[x]=1;
		int temp[n],pos=0;
		for(int i=0;i<n;i++){
			if(a[x][i])temp[pos++]=i;
		}
		for(int i=0;i<pos;i++){
			if(!vis[temp[i]])dfs(temp[i]);
		}
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		ma m;
	}
}
