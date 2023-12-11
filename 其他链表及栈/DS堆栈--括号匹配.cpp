#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		stack<char>s;
		string a;
		cin>>a;
		s.push(1);
		for(int i=0;i<a.size();i++){
			if(a[i]=='('||a[i]=='['||a[i]=='{'){
				s.push(a[i]);
			}
			if(a[i]==')'){
				if(s.top()=='(')s.pop();
				else s.push(a[i]);
			}
			if(a[i]==']'){
				if(s.top()=='[')s.pop();
				else s.push(a[i]);
			}
			if(a[i]=='}'){
				if(s.top()=='{')s.pop();
				else s.push(a[i]);
			}
		}
		if(s.top()==1){
			cout<<"ok"<<endl;
		}else{
			cout<<"error"<<endl;
		}
	}
}
