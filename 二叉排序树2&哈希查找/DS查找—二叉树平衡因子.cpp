#include <bits/stdc++.h>
using namespace std;
class tree{
	public:
	char *s;
	int n;
	tree(){
		cin>>n;
		s=new char[n+1];
		for(int i=1;i<=n;i++)cin>>s[i];
	}
	void houxubianli(){
		houxubianli(1);
	}
	void houxubianli(int x){
		if(x<=n&&s[x]!='0'){
			houxubianli(x*2);
			houxubianli(x*2+1);
			if(x*2>n){
				cout<<s[x]<<" 0"<<endl;
			}else if(x*2==n&&x*2+1>n){
				cout<<s[x]<<" 1"<<endl;
			}else{
				int l=0,r=0;
				findmaxdepth(x*2,0,l);
				findmaxdepth(x*2+1,0,r);
				int temp=l-r;
				cout<<s[x]<<" "<<temp<<endl;
			}
		}
	}
	void findmaxdepth(int x,int now,int &sum){
		if(x<=n&&s[x]!='0'){
			sum=max(sum,++now);
			findmaxdepth(x*2,now,sum);
			findmaxdepth(x*2+1,now,sum);
		}
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		tree t1;
		t1.houxubianli();
	}
}
