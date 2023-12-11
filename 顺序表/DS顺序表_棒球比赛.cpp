#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		char op;
		stack<int>s;
		for(int i=1;i<=n;i++){
			cin>>op;
			if(op>='0'&&op<='9'){
				s.push(op-'0');
			}else if(op=='+'){
				int x=s.top();
				s.pop();
				int x2=s.top()+x;
				s.push(x);
				s.push(x2);
			}else if(op=='C'){
				s.pop();
			}else if(op=='D'){
				s.push(2*s.top());
			}
		}
		int sum=0,count=0,a[10000];
		while(!s.empty()){
			a[count++]=s.top();
			s.pop();
		}
		cout<<count<<" ";
		for(int i=count-1;i>=0;i--){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}
