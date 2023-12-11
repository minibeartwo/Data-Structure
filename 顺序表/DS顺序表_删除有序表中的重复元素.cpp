#include <bits/stdc++.h>
using namespace std;
class sb{
	int *a,size,maxsize;
	public:
		sb(){
			a=new int[1000];
			maxsize=1000;
			size=0;
		}
		~sb(){
			delete []a;
		}
		void pushback(int i){
			a[size]=i;
			size++;
		}
		void display(){
		    cout<<size<<" ";
		    int i;
		    for(i=0;i<size;i++){
		    	cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		void del(int i){
			if(i<1||i>size){
				return;
			}
			for(int j=i-1;j<size-1;j++){
				a[j]=a[j+1];
			}
			size--;
		}
		void chachong(int n){
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(a[i]==a[j]){
						del(j);
						j--;
						n--;
					}
				}
				
			}
			size=n;
		}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==0){
			cout<<0;
			continue;
		}
		sb m;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			m.pushback(x);
		}
		m.chachong(n);
		m.display();
	}
}
