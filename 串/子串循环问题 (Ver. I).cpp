#include <bits/stdc++.h>
using namespace std;
void kmp(string a){
	int len=a.size();
	int i=0,j=-1;
	int *next=new int[len+1];
	next[0]=-1;
	while(i<len){
		if(j==-1||a[i]==a[j]){
			next[++i]=++j;
		}else{
			j=next[j];
		}
	}
	int t=next[len];
	if(len%(len-t)==0){
		if(next[len]==0){
			cout<<len<<endl;
		}else{
			cout<<0<<endl;
		}
	}else{
		cout<<len-t-(t%(len-t))<<endl;
	}
}
int main(){
	int n;
	cin>>n;
	while(n--){
		string a;
		cin>>a;
		kmp(a);
	}
}
