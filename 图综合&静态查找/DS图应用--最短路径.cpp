#include <bits/stdc++.h>
using namespace std;
int path[1100][1100],n,dis[1100],flag[1100];
queue<int>q[1100];
int findmin(){
	int minn=0x7fffffff,k=-1;
	for(int i=0;i<n;i++){
		if(minn>dis[i]&&!flag[i]){
			minn=dis[i];
			k=i;
		}
	}
	return k;
}
void dijkstra(int x){
	dis[x]=0;
	for(int i=0;i<n;i++)while(q[i].size())q[i].pop();
	for(int i=0;i<n;i++){
		int k=findmin();
		flag[k]=1;
		for(int j=0;j<n;j++){
			if(path[k][j]&&dis[j]>dis[k]+path[k][j]){
				dis[j]=dis[k]+path[k][j];
				while(q[j].size()){
					q[j].pop();
				}
				queue<int>temp=q[k];
				while(temp.size()){
					q[j].push(temp.front());
					temp.pop();
				}
				q[j].push(k);
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;i++)dis[i]=0x7fffffff;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)cin>>path[i][j];
		}
		int x;
		cin>>x;
		dijkstra(x);
		for(int i=0;i<n;i++){
			if(i==x)continue;
			cout<<x<<"-"<<i<<"-"<<dis[i]<<"----"<<"[";
			while(q[i].size()){
				cout<<q[i].front()<<" ";
				q[i].pop();
			}
			cout<<i<<" ";
			cout<<"]"<<endl;
		}
	}
}
