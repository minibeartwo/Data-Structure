#include <bits/stdc++.h>
using namespace std;
double ma[35][35];
map<string,int>m;
bool floyd(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(ma[i][j]<ma[i][k]*ma[k][j]){
					ma[i][j]=ma[i][k]*ma[k][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(ma[i][i]>1)return true;
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(ma,0,sizeof(ma));
		int x,y;
		cin>>x>>y;
		for(int i=0;i<x;i++){
			string a;
			cin>>a;
			pair<string,int>b(a,i);
			m.insert(b);
			ma[i][i]=1;
		}
		for(int i=0;i<y;i++){
			string a,b;
			double rate;
			cin>>a>>rate>>b;
			ma[m[a]][m[b]]=rate;
		}
		if(floyd(x)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		m.clear();
	}
}
