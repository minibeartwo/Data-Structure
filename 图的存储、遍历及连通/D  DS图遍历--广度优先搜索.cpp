#include <bits/stdc++.h>
using namespace std;
class ma{
	public:
	int **a,n,*vis;
	queue<int>q;
	ma(){
		cin>>n;
		a=new int*[n];
		vis=new int[n];
		for(int i=0;i<n;i++)vis[i]=0;
		for(int i=0;i<n;i++)a[i]=new int[n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)cin>>a[i][j];
		}
		for(int i=0;i<n;i++){
			if(!vis[i])bfs(i);
		}
		cout<<endl;
	}
	void bfs(int x){
		cout<<x<<" ";
		vis[x]=1;
		for(int i=0;i<n;i++){
			if(a[x][i])q.push(i);
		}
		while(q.size()){
			if(!vis[q.front()])bfs(q.front());
			if(q.size())q.pop();
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
