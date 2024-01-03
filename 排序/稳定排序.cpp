#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct node{
	int a,b,index;
}m[maxn];
bool cmp(node a1,node b){
	if(a1.a==b.a)return a1.index<b.index;
	return a1.a<b.a;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d %d",&m[i].a,&m[i].b);
			m[i].index=i;
		}
		sort(m,m+n,cmp);
		for(int i=0;i<n;i++)printf("%d %d\n",m[i].a,m[i].b);
	}
}
