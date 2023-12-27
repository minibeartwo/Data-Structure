#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int haxi[maxn],n;
void insert(int x){
	int count=0,now=x%11;
	while(1){
		if(count>=n)break;
		if(haxi[now]==-1){
			haxi[now]=x;
			break;
		}
		++now%=n;
		count++;
	}
}
void find(int x){
	int count=1,now=x%11;
	while(haxi[now]!=x&&haxi[now]!=-1&&count<n){
		++now%=n;
		count++;
	}
	if(haxi[now]==-1||count>=n){
		cout<<0<<" "<<count<<endl;
	}else{
		cout<<1<<" "<<count<<" "<<now+1<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int m;
		cin>>n>>m;
		memset(haxi,-1,sizeof(haxi));
		while(m--){
			int x;
			cin>>x;
			insert(x);
		}
		for(int i=0;i<n;i++){
			if(haxi[i]!=-1){
				cout<<haxi[i]<<" ";
			}else{
				cout<<"NULL"<<" "; 
			}
		}
		cout<<endl;
		cin>>m;
		while(m--){
			int x;
			cin>>x;
			find(x);
		}
	}
}
