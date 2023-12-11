#include <bits/stdc++.h>
using namespace std;
struct position{
	int x,y;
};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,size;
		cin>>n;
		size=n;
		int a[n][n];
		stack<position>s;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		if(a[0][0]==1){
			cout<<"no path"<<endl;
			continue;
		}
		int i=0,j=0;
		s.push({0,0});
		while(1){
			if(s.empty()||(i==n-1&&j==n-1))break;
			if(j+1<size&&a[i][j+1]==0){
				a[i][++j]=1;
				s.push({i,j});
			}else if(i+1<size&&a[i+1][j]==0){
				a[++i][j]=1;
				s.push({i,j});
			}else if(j-1>=0&&a[i][j-1]==0){
				a[i][--j]=1;
				s.push({i,j});
			}else if(i-1>=0&&a[i-1][j]==0){
				a[--i][j]=1;
				s.push({i,j});
			}else{
				i=s.top().x;
				j=s.top().y;
				if(!((j+1<size&&a[i][j+1]==0)||(i+1<size&&a[i+1][j]==0)||(j-1>=0&&a[i][j-1]==0)||(i-1>=0&&a[i-1][j]==0))){
					s.pop();
				}
			}
		}
		if(!s.empty()){
			stack<position>ans;
			while(s.size()){
				ans.push(s.top());
				s.pop();
			}
			i=0;
			while(ans.size()){
				cout<<'['<<ans.top().x<<','<<ans.top().y<<"]--";
				i++;
				if(i%4==0)cout<<endl;
				ans.pop();
			}
			cout<<"END"<<endl;
		}else{
			cout<<"no path"<<endl;
		}
	}
}
