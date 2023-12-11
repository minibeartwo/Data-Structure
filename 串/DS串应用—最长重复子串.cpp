#include <bits/stdc++.h>
using namespace std;
class mystring{
	string p;
	int size;
	public:
		mystring(){}
		~mystring(){
			p="";
			size=0;
		}
		int getnext(){
			int len=size;
			int i=0,j=-1,*next=new int[len+1];
			next[0]=-1;
			while(i<len){
				if(j==-1||p[i]==p[j]){
					next[++i]=++j;
				}else{
					j=next[j];
				}
			}
			int ans=-1;
			for(int i=0;i<=len;i++){
				if(next[i]*2<len){
					ans=max(ans,next[i]);
				}
			}
			delete []next;
			return ans;
		}
		void setstring(string a){
			p=a;
			size=a.size();
		}
};
int main(){
	int n;
	cin>>n;
	while(n--){
		string a;
		cin>>a;
		mystring sb;
		int len=a.size(),ans=-1;
		for(int i=0;i<len;i++){
			sb.setstring(a.substr(i));
			ans=max(sb.getnext(),ans);
		}
		if(ans==0)ans=-1;
		cout<<ans<<endl;
	}
}
