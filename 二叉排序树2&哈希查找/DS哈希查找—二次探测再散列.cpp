#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,haxi[maxn];
void insert(int x){
	int key=x%11,i=1,flag=1;
	if(haxi[key]==-1){
		haxi[key]=x;
		return;
	}
	while(1){
		if(flag){
			int temp=(key+i*i)%n;
			if(haxi[temp]==-1){
				haxi[temp]=x;
				return;
			}
			flag=0;
		}else{
			int temp=key-i*i;
			while(temp<0)temp+=n;
			if(haxi[temp]==-1){
				haxi[temp]=x;
				return;
			}
			flag=1;
		}
		if(flag){
			i++;
		}
	}
}
void find(int x){
	int key=x%11,count=1,flag=1,i=1;
	if(haxi[key]==x){
		cout<<"1 "<<count<<" "<<key+1<<endl;
		return;
	}else if(haxi[key]==-1){
		cout<<"0 "<<count<<endl;
		return;
	}
	while(1){
		if(flag){
			int temp=(key+i*i)%n;
			if(haxi[temp]==x){
				cout<<"1 "<<count+1<<" "<<temp+1<<endl;
				return;
			}else if(haxi[temp]==-1||temp==key){
				cout<<"0 "<<count+1<<endl;
				return;
			}
			flag=0;
		}else{
			int temp=(key-i*i)%n;
			if(temp<0)temp+=n;
			if(haxi[temp]==x){
				cout<<"1 "<<count+1<<" "<<temp+1<<endl;
				return;
			}else if(haxi[temp]==-1||temp==key){
				cout<<"0 "<<count+1<<endl;
				return;
			}
			flag=1;
		}
		count++;
		if(count>=n){
			cout<<"0 "<<count<<endl;
			return;
		}
		if(flag){
			i++;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
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
