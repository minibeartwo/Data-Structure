#include <bits/stdc++.h>
using namespace std;
class seqlist{
	int *list,maxsize,size;
	public:
		seqlist(){
			maxsize=1000;
			size=0;
			list=new int[maxsize];
		}
		~seqlist(){
			delete []list;
		}
		int listsize(){
			return size;
		}
		int listinsert(int i,int item){
			if(i<=0||i>size+1){
				return 0;
			}
			int j;
			for(j=size;j>i-1;j--){
				list[j]=list[j-1];
			}
			list[j]=item;
			size++;
			return 1;
		}
		int listdel(int i){
			if(i<=0||i>size){
				return 0;
			}
			for(int j=i-1;j<size;j++){
				list[j]=list[j+1];
			}
			size--;
			return 1;
		}
		int get(int i){
			if(i<=0||i>size){
				return 0;
			}
			return list[i-1];
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
	seqlist m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		m.listinsert(i,x);
	}
	m.display();
	int a,b;
	cin>>a>>b;
	if(m.listinsert(a,b)){
		m.display();
	}else{
		cout<<"error"<<endl;
	}
	cin>>a>>b;
	if(m.listinsert(a,b)){
		m.display();
	}else{
		cout<<"error"<<endl;
	}
	cin>>a;
	if(m.listdel(a)){
		m.display();
	}else{
		cout<<"error"<<endl;
	}
	cin>>a;
	if(m.listdel(a)){
		m.display();
	}else{
		cout<<"error"<<endl;
	}
	cin>>a;
	if(m.get(a)){
		cout<<m.get(a)<<endl;
	}else{
		cout<<"error"<<endl;
	}
	cin>>a;
	if(m.get(a)){
		cout<<m.get(a)<<endl;
	}else{
		cout<<"error"<<endl;
	}
}
