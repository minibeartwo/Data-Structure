#include <bits/stdc++.h>
using namespace std;
class ma{
	public:
	int **a;
	string *b;
	char type;
	int n,m;
	ma(){
		cin>>type>>n;
		a=new int*[n];
		b=new string[n];
		for(int i=0;i<n;i++)cin>>b[i];
		for(int i=0;i<n;i++){
			a[i]=new int[n];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)a[i][j]=0;
		}
		cin>>m;
		for(int i=0;i<m;i++){
			string c,d;
			cin>>c>>d;
			int e=find(c),f=find(d);
			a[e][f]=1;
			if(type=='U'){
				a[f][e]=1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)cout<<a[i][j]<<' ';
			cout<<endl; 
		}
		for(int i=0;i<n;i++){
			if(type=='D'){
				int x=0,y=0;
				for(int j=0;j<n;j++){
					x+=a[i][j];
					y+=a[j][i];
				}
				if(x||y){
					cout<<b[i]<<": "<<x<<" "<<y<<" "<<x+y<<endl;
				}else{
					cout<<b[i]<<endl;
				}
			}else{
				int x=0;
				for(int j=0;j<n;j++)x+=a[i][j];
				if(x){
					cout<<b[i]<<": "<<x<<endl;
				}else{
					cout<<b[i]<<endl;
				}
			}
		}
	}
	int find(string x){
		for(int i=0;i<n;i++){
			if(b[i]==x){
				return i;
			}
		}
		return 0;
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		ma m;
	}
}
