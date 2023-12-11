#include <bits/stdc++.h>
using namespace std;
int main(){
	string a,b,c;
	while(cin>>a){
		cin>>b>>c;
		int a1[26]={0},b1[26]={0};
		for(int i=0;i<a.size();i++){
			a1[a[i]-'A']++;
		}
		for(int i=0;i<b.size();i++){
			b1[b[i]-'A']++;
		}
		int count1=0,count2=0,flag=1;
		for(int i=0;i<c.size();i++){
			if(!a1[c[i]-'A']&&!b1[c[i]-'A']){
				flag=0;
				break;
			}
			if(a1[c[i]-'A']){
				count1++;
				a1[c[i]-'A']--;
				if(b1[c[i]-'A']){
					count2++;
				}
			}else if(b1[c[i]-'A']){
				count2++;
				b1[c[i]-'A']--;
			}
		}
		if((count1>=c.size()/2&&count2>=c.size()/2)&&flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
} 
