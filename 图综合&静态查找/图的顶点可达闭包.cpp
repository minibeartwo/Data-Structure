#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n][n]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int flag=1;
	while(flag){
		flag=0;
		for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]){
				for(int k=0;k<n;k++){
					if(a[j][k]&&!a[i][k]){
						    flag=1;
						    a[i][k]=1;
					    }
			 	    }
			    }
		    }
	    }
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
