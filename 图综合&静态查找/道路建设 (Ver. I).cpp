#include <bits/stdc++.h>
using namespace std;
class ma{
	public:
	int **a,n;
	bool *vis;
	ma(int nn){
		n=nn;
		a=new int*[n];
		vis=new bool[n];
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)a[i]=new int[n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)cin>>a[i][j];
		}
		int t;
		cin>>t;
		while(t--){
			int x,y;
			cin>>x>>y;
			a[x-1][y-1]=0;
			a[y-1][x-1]=0;
		}
		vis[0]=1;
		int sum=0;
		while(!check()){
			int minn=9999,e=-1;
			for(int i=0;i<n;i++){
				if(vis[i]){
					for(int j=0;j<n;j++){
						if(minn>a[i][j]&&!vis[j]){
							minn=a[i][j];
							e=j;
						}
					}
				} 
			}
			sum+=minn;
			vis[e]=1;
		}
		cout<<sum<<endl;
	}
	bool check(){
		for(int i=0;i<n;i++){
			if(!vis[i])return false;
		}
		return true;
	}
};
int main(){
	int n;
	while(cin>>n){
		ma m(n);
	}
}
