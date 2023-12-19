#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		double x;
		cin>>x;
		double left=0,right=x,mid;
		do{
			mid=(left+right)/2;
			if(mid*mid>x){
				right=mid;
			}else{
				left=mid;
			}
		}while(fabs(mid*mid-x)>=0.00001);
		cout<<fixed<<setprecision(3)<<mid<<endl;
	}
}
