#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[n]={0};
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		queue<int>q;
		sort(a,a+n);
		int minn=0x7fffffff;
		for(int i=0;i<n-1;i++){
			if(a[i+1]-a[i]<minn){
				minn=a[i+1]-a[i];
				while(q.size())q.pop();
				q.push(a[i]);
				q.push(a[i+1]);
			}else if(a[i+1]-a[i]==minn){
				q.push(a[i]);
				q.push(a[i+1]);
			}
		}
		while(q.size()){
			int x=q.front();
			q.pop();
			int y=q.front();
			q.pop();
			cout<<"["<<x<<","<<y<<"] ";
		}
		cout<<endl;
	}
}
