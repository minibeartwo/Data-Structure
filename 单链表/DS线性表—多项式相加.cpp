#include <bits/stdc++.h>
using namespace std;
class sqlist{
	public:
		int *elem,size,length;
		sqlist(){
			elem=new int[100];
			size=100;
			length=0;
		}
		~sqlist(){
			elem=NULL;
			size=0;
			length=0;
		}
}; 
int main(){
	int i,j,t;
	cin>>t;
	while(t--){
		sqlist L11,L12,L21,L22,L31,L32;
		int n1,n2;
		cin>>n1;
		for(int i=0;i<n1;i++){
			cin>>L11.elem[i]>>L12.elem[i];
		}
		for(int i=0;i<n1;i++){
			if(L12.elem[i]<0){
				if(L11.elem[i]<0){
					cout<<"("<<L11.elem[i]<<")x^("<<L12.elem[i]<<")";
				}else{
					cout<<L11.elem[i]<<")x^("<<L12.elem[i]<<")";
				}
			}else if(L12.elem[i]>0){
				if(L11.elem[i]<0){
					cout<<"("<<L11.elem[i]<<")x^"<<L12.elem[i];
				}else{
					cout<<L11.elem[i]<<"x^"<<L12.elem[i];
				}
			}else{
				if(L11.elem[i]<0){
					cout<<"("<<L11.elem[i]<<")";
				}else{
					cout<<L11.elem[i];
				}
			}
			if(i!=n1-1){
				cout<<" + ";
			}
		}
		cout<<endl;
		cin>>n2;
		for(int i=0;i<n2;i++){
			cin>>L21.elem[i]>>L22.elem[i];
		}
		for(int i=0;i<n2;i++){
			if(L22.elem[i]<0){
				if(L21.elem[i]<0){
					cout<<"("<<L21.elem[i]<<")x^("<<L22.elem[i]<<")";
				}else{
					cout<<L21.elem[i]<<"x^("<<L22.elem[i]<<")";
				}
			}else if(L22.elem[i]>0){
				if(L21.elem[i]<0){
					cout<<"("<<L21.elem[i]<<")x^"<<L22.elem[i];
				}else{
					cout<<L21.elem[i]<<"x^"<<L22.elem[i];
				}
			}else{
				if(L21.elem[i]<0){
					cout<<"("<<L21.elem[i]<<")";
				}else{
					cout<<L21.elem[i];
				}
			}
			if(i!=n2-1){
				cout<<" + ";
			}
		}
		cout<<endl;
		int i=0,j=0,k=0;
		while(i!=n1&&j!=n2){
			if(L12.elem[i]<L22.elem[j]){
				L32.elem[k]=L12.elem[i];
				L31.elem[k]=L11.elem[i];
				k++;
				i++;
				continue;
			}else if(L12.elem[i]==L22.elem[j]){
				if(L11.elem[i]+L21.elem[j]==0){
					i++;
					j++;
					continue;
				}else{
					L32.elem[k]=L12.elem[i];
					L31.elem[k++]=L11.elem[i++]+L21.elem[j++];
				continue;
				}
				
			}else{
				L32.elem[k]=L22.elem[j];
				L31.elem[k++]=L21.elem[j++];
			}
		}
		while(j!=n2){
			L32.elem[k]=L22.elem[j];
			L31.elem[k++]=L21.elem[j++];
		}
		while(i!=n1){
			L32.elem[k]=L12.elem[i];
			L31.elem[k++]=L11.elem[i++];
		}
		for(int i=0;i<k;i++){
			if(L32.elem[i]<0){
				if(L31.elem[i]<0){
					cout<<"("<<L31.elem[i]<<")x^("<<L32.elem[i]<<")";
				}else{
					cout<<L31.elem[i]<<"x^("<<L32.elem[i]<<")";
				}
			}else if(L32.elem[i]>0){
				if(L31.elem[i]<0){
					cout<<"("<<L31.elem[i]<<")x^"<<L32.elem[i];
				}else{
					cout<<L31.elem[i]<<"x^"<<L32.elem[i];
				}
			}else{
				if(L31.elem[i]<0){
					cout<<"("<<L31.elem[i]<<")";
				}else{
					cout<<L31.elem[i];
				}
			}
			if(i!=k-1){
				cout<<" + ";
			}
		}
		cout<<endl;
	}
}
