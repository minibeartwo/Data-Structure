#include <bits/stdc++.h>
using namespace std;
int find(int a,int *b,int **c,int d){
	for(int i=0;i<a;i++){
		for(int j=0;j<b[i];j++){
			if(c[i][j]==d){
				return i;
			}
		}
	}
	return -1;
}
int main(){
	int t;
	cin>>t;
	int **a=new int*[t];
	int len[t];
	for(int i=0;i<t;i++){
		cin>>len[i];
		a[i]=new int[len[i]];
		for(int j=0;j<len[i];j++){
			cin>>a[i][j];
		}
	}
	string b;
	queue<int>order;
	queue<int>*line=new queue<int>[t];
	int flag=0;
	while(cin>>b&&b!="STOP"){
		if(b=="ENQUEUE"){
			int x;
	     	cin>>x;
			int type=find(t,len,a,x);
			if(type>=0){
				if(line[type].empty()){
					order.push(type);
				}
				line[type].push(x);
			}
		}else if(b=="DEQUEUE"){
			if(flag){
				cout<<" ";
			}
			if(!order.empty()&&!line[order.front()].empty()){
				cout<<line[order.front()].front();
				line[order.front()].pop();
				if(line[order.front()].empty()){
					order.pop();
				}
			}
			flag=1;
		}
	}
}
