#include <bits/stdc++.h>
using namespace std;
int main(){
	stack<int>s;
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]==a[0]){
			s.push(i);
		}else{
			cout<<s.top()<<" "<<i<<endl;
			s.pop();
		}
	}
}
