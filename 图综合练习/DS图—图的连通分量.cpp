#include <bits/stdc++.h>
using namespace std;
class ma{
	public:
		int **a,*vis;
		int n;
		string *b;
		void dfs(int x){
			vis[x]=1;
			int c[n]={0},pos=0;
			for(int i=0;i<n;i++){
				if(a[x][i])c[pos++]=i;
			}
			for(int i=0;i<pos;i++){
				if(!vis[c[i]])dfs(c[i]);
			}
		} 
		ma(){
			cin>>n;
			vis=new int[n];
			b=new string[n];
			a=new int*[n];
			for(int i=0;i<n;i++)vis[i]=0;
			for(int i=0;i<n;i++){
				a[i]=new int[n];
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)a[i][j]=0;
			}
			for(int i=0;i<n;i++)cin>>b[i];
			int m;
			cin>>m;
			for(int i=0;i<m;i++){
				string x,y;
				cin>>x>>y;
				int x1=find(x),y1=find(y);
				a[x1][y1]=1;
				a[y1][x1]=1;
			}
			for(int i=0;i<n;i++)cout<<b[i]<<" ";
			cout<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
			int ans=0;
			for(int i=0;i<n;i++){
				if(vis[i]==0){
					ans++;
					dfs(i);
				}
			}
			cout<<ans<<endl; 
		}
		int find(string a){
			for(int i=0;i<n;i++){
				if(a==b[i])return i;
			}
			return -1;
		}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		ma m;
	}
}
