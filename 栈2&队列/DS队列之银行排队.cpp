#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	queue<char>q;
	for(int i=0;i<n;i++){
		char op;
		cin>>op;
		q.push(op);
	}
	int c1=0,c2=0,c3=0;
	int count1=0,count2=0,count3=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(q.front()=='A'){
			count1+=x;
			c1++;
		}else if(q.front()=='B'){
			count2+=x;
			c2++;
		}else if(q.front()=='C'){
			count3+=x;
			c3++;
		}
		q.pop();
	}
	cout<<count1/c1<<endl<<count2/c2<<endl<<count3/c3<<endl;
}
