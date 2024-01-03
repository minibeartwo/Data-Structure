#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n]={0},maxn=-1;
		for(int i=0;i<n;i++){
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
		int count=0,k=1,sum=0;
		while(maxn){
			maxn/=10;
			count++;
		}
		queue<int>b[10];
		while(sum<count){
			for(int i=0;i<n;i++){
				int temp=(a[i]/k)%10;
				b[temp].push(a[i]);
			}
			queue<int>s[10];
			for(int i=0;i<10;i++)s[i]=b[i];
			for(int i=0;i<10;i++){
				cout<<i<<":";
				if(s[i].size()){
					cout<<"->"; 
					while(s[i].size()){
						cout<<s[i].front()<<"->";
						s[i].pop();
					}
					cout<<"^"<<endl;
				}else{
					cout<<"NULL"<<endl;
				}
			}
			int m=0;
			for(int i=0;i<10;i++){
				while(b[i].size()){
					a[m++]=b[i].front();
					b[i].pop();
				}
			}
			for(int i=0;i<n;i++){
				if(i==n-1)cout<<a[i]<<endl;
				else cout<<a[i]<<" ";
			}
			k*=10;
			sum++;
		}
		cout<<endl;
	}
}
