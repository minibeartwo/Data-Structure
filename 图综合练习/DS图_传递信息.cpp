#include <bits/stdc++.h>
using namespace std;
int a[110][110],ans=0;
void dfs(int now,int lunshu,int n){
	if(now==n-1&&lunshu==0){
		ans++;
		return;
	}else if(lunshu<0)return;
	for(int i=0;i<n;i++){
		if(a[now][i])dfs(i,lunshu-1,n);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		ans=0;
		cin>>n>>m;
		memset(a,0,sizeof(a));
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			a[x][y]=1;
		}
		int x;
		cin>>x;
		dfs(0,x,n);
		cout<<ans<<endl;
	}
}
