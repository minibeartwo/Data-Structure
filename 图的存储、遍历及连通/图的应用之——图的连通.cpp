#include <bits/stdc++.h>
using namespace std;
class ma{
	public:
	int **a,*vis,n,sum;
	ma(int x){
		n=x;
		a=new int*[n];
		vis=new int[n];
		for(int i=0;i<n;i++){
			a[i]=new int[n];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)cin>>a[i][j];
		}
	}
	int check(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)vis[j]=0;
			sum=0;
			dfs(i);
			if(sum!=n){
				return 0;
			}
		}
		return 1;
	}
	void dfs(int x){
		vis[x]=1;
		sum++;
		int temp[n]={0},cnt=0;
		for(int i=0;i<n;i++){
			if(a[x][i])temp[cnt++]=i;
		}
		for(int i=0;i<cnt;i++){
			if(!vis[temp[i]])dfs(temp[i]);
		}
	}
}; 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ma m(n);
		if(m.check()){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
