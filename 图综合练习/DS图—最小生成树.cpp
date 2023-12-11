#include <bits/stdc++.h>
using namespace std;
string name[110];
struct edge1{
	int from,to,w;
};
class kruskal{
	public:
	int n,m,parent[110],count;
	edge1 s[110];
	kruskal(int a,int b){
		count=0;
		n=a;
		m=b;
		for(int i=0;i<n;i++)parent[i]=-1;
	}
	void insert(int a,int b,int c){
		s[count].from=a;
		s[count].to=b;
		s[count++].w=c;
	}
	void paixu(){
		for(int i=0;i<m-1;i++){
			for(int j=i+1;j<m;j++){
				if(s[i].w>s[j].w){
					edge1 temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
			}
		}
	}
	int findparent(int x){
		while(parent[x]>-1){
			x=parent[x];
		}
		return x;
	}
	void display(){
		cout<<"kruskal:"<<endl;
		paixu();
		int num=0;
		for(int i=0;i<m;i++){
			int a=findparent(s[i].from);
			int b=findparent(s[i].to);
			if(a!=b){
				if(name[s[i].from]<name[s[i].to]){
					cout<<name[s[i].from]<<" "<<name[s[i].to]<<" "<<s[i].w<<endl;
				}else{
					cout<<name[s[i].to]<<" "<<name[s[i].from]<<" "<<s[i].w<<endl;
				}
				parent[a]=b;
				num++;
				if(num==n-1)return;
			}
		}
	}
};
int find(string a,int n){
	for(int i=0;i<n;i++){
		if(a==name[i])return i;
	}
	return 0;
}
struct edge2{
	int w=0,p=0;
};
class prim{
	public:
	int n,ma[110][110];
	prim(int x){
		n=x;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)ma[i][j]=9999;
		}
	}
	void insert(int a,int b,int c){
		ma[a][b]=c;
		ma[b][a]=c;
	}
	int findmin(edge2 *s){
		int k=0,minn=9999;
		for(int i=0;i<n;i++){
			if(minn>s[i].w&&s[i].w){
				minn=s[i].w;
				k=i;
			}
		}
		return k;
	}
	void display(int x){
		edge2 s[n];
		for(int i=0;i<n;i++){
			s[i].w=ma[x][i];
			s[i].p=x;
		}
		s[x].w=0;
		int sum=0;
		for(int i=0;i<n-1;i++){
			int k=findmin(s);
			sum+=s[k].w;
			s[k].w=0;
			for(int j=0;j<n;j++){
				if(s[j].w>ma[k][j]){
					s[j].w=ma[k][j];
					s[j].p=k;
				}
			}
		}
		cout<<sum<<endl;
		cout<<"prim:"<<endl;
		for(int i=0;i<n;i++){
			s[i].w=ma[x][i];
			s[i].p=x;
		}
		s[x].w=0;
		for(int i=0;i<n-1;i++){
			int k=findmin(s);
			cout<<name[s[k].p]<<" "<<name[k]<<" "<<s[k].w<<endl;
			s[k].w=0;
			for(int j=0;j<n;j++){
				if(s[j].w>ma[k][j]){
					s[j].w=ma[k][j];
					s[j].p=k;
				}
			}
		}
	}
};
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>name[i];
	int m;
	cin>>m;
	prim p(n);
	kruskal k(n,m);
	while(m--){
		int c;
		string a,b;
		cin>>a>>b>>c;
		int e=find(a,n),f=find(b,n);
		k.insert(e,f,c);
		p.insert(e,f,c);
	}
	string a;
	cin>>a;
	int x=find(a,n);
	p.display(x);
	k.display();
}
