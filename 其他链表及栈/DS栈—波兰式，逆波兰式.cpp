#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string a;
		string an[1001];
		cin>>a;
		stack<char>sw;
		int len=a.size(),k=0;
		for(int i=len-1;i>=0;i--){
			if(a[i]>='0'&&a[i]<='9'){
				string temp="";
				temp=a[i]+temp;
				i--;
				while(a[i]>='0'&&a[i]<='9'){
					temp=a[i]+temp;
					i--;
				}
				i++;
				an[k++]=temp;
				continue;
			}
			if(a[i]=='('){
				while(sw.top()!=')'){
					an[k++]=sw.top();
					sw.pop();
				}
				sw.pop();
			}else{
				if(a[i]==')')sw.push(a[i]);
				while(a[i]=='+'||a[i]=='-'||a[i]=='/'||a[i]=='*'){
					if(sw.empty()){
						sw.push(a[i]);
						break;
					}else{
						if(a[i]=='+'&&(sw.top()=='*'||sw.top()=='/')||a[i]=='-'&&(sw.top()=='*'||sw.top()=='/')){
							an[k++]=sw.top();
							sw.pop();
						}else{
							sw.push(a[i]);
							break;
						}
					}
				}
			}
		}
		while(sw.size()){
			an[k++]=sw.top();
			sw.pop();
		}
		for(int i=k-1;i>=0;i--){
			cout<<an[i];
			if(i)cout<<" ";
			else puts("");
		}
		stack<char>s;
		k=0;
		string ans[1001];
		for(int i=0;i<len;i++){
			if(a[i]>='0'&&a[i]<='9'){
				int temp=a[i]-'0';
				i++;
				while(a[i]>='0'&&a[i]<='9'){
					temp=temp*10+a[i]-'0';
					i++;
				}
				i--;
				ans[k++]=to_string(temp);
			}
			if(a[i]==')'){
				while(s.top()!='('){
					ans[k++]=s.top();
					s.pop();
				}
				if(s.top()=='('){
					s.pop();	
				}
			}else{
				if(a[i]=='('){
					s.push(a[i]);
				}
				
					while(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'){
						if(s.empty()||s.top()=='('||a[i]=='*'&&(s.top()=='+'||s.top()=='-'||s.top()=='/')||a[i]=='/'&&(s.top()=='+'||s.top()=='-'||s.top()=='*')||a[i]=='+'&&s.top()=='-'||a[i]=='-'&&s.top()=='+'){
							s.push(a[i]);
							break;
						}else{
							while(s.size()){
								ans[k++]=s.top();
								s.pop();
							}
						}
					}
				
			}
		}
		while(s.size()){
			ans[k++]=s.top();
			s.pop();
		}
		for(int i=0;i<k;i++){
			cout<<ans[i];
			if(i!=k-1)cout<<" ";
		}
		if(t){
			puts("");
			puts("");
		}
	}
}
