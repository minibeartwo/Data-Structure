#include <bits/stdc++.h>
using namespace std;
struct fenkuai{
	int maxn,index;
};
class li{
	public:
	int *a,len1,len2;
	fenkuai *b;
	li(int x){
		len1=x;
		a=new int[len1];
		for(int i=0;i<len1;i++)cin>>a[i];
		cin>>len2;
		b=new fenkuai[len2];
		for(int i=0;i<len2;i++)cin>>b[i].maxn;
		int now=0;
		for(int i=0;i<len1;i++){
			if(a[i]>b[now].maxn){
				b[now++].index=i-1;
			}
		}
		b[len2-1].index=len1-1;
	}
	void find(int x){
		int i,j,k;
		int sum=0;
		if(x<=b[0].maxn){
			i=0;
			j=b[0].index;
			sum++;
		}else if(x>b[len2-1].maxn){
			cout<<"error"<<endl;
			return;
		}else{
			for(k=0;k<len2;k++){
				sum++;
				if(b[k].maxn>=x){
					i=b[k-1].index+1;
					j=b[k].index;
					break;
				}
			}
		}
		for(k=i;k<=j;k++){
			sum++;
			if(a[k]==x){
				cout<<k+1<<"-"<<sum<<endl;
				return;
			}
		}
		cout<<"error"<<endl;
	}
}; 
int main(){
	int n;
	while(cin>>n){
		li l(n);
		int m;
		cin>>m;
		while(m--){
			int x;
			cin>>x;
			l.find(x);
		}
	}
}
