#include <bits/stdc++.h>
using namespace std;
class seqlist{
	int *list,size,maxsize;
	public:
		seqlist(int n){
			size=n;
			maxsize=1000;
			list=new int[maxsize];
			for(int i=0;i<n;i++)cin>>list[i];
			display();
		}
		~seqlist(){
			delete []list;
		}
		void multiinsert(int i, int n, int item[]){
			int pos=i-1;
			for(int j=size-1;j>=i-1;j--){
				list[j+n]=list[j];
			}
			for(int j=0;j<n;j++){
				list[pos+j]=item[j];
			}
			size+=n;
			display();
		}
		void multidel(int i, int n){
			int pos=i-1;
			for(int j=0;j<n;j++){
				list[pos+j]=list[pos+j+n];
			}
			size-=n;
			display();
		}
		void display(){
			cout<<size<<" ";
			for(int i=0;i<size;i++){
				cout<<list[i]<<" ";
			}
			cout<<endl;
		}
};
int main(){
	int n;
	cin>>n;
	seqlist m(n);
	int a,b;
	cin>>a>>b;
	int sb[b];
	for(int i=0;i<b;i++)cin>>sb[i];
	m.multiinsert(a,b,sb);
	cin>>a>>b;
	m.multidel(a,b);
}
