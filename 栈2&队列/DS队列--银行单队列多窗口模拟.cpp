#include <bits/stdc++.h>
using namespace std;
struct people{
	int t=0,p=0,curwt=0,waitstate=0,wait=0;
}; 
int main(){
	queue<people>list;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		people temp;
		cin>>temp.t>>temp.p;
		list.push(temp);
	}
	int w;
	cin>>w;
	queue<people>*windows=new queue<people>[w];
	for(int i=0;i<w;i++){
		people p;
		windows[i].push(p);
	}
	queue<people>last;
	while(list.size()){
		int curw=0,mint=999;
		while(curw<w){
			if(!windows[curw].empty()){
				if(mint>windows[curw].front().curwt){
					mint=windows[curw].front().curwt;
				}
			}
			curw++;
		}
		curw=0;
		while(curw<w){
			if(windows[curw].size()){
				if(mint==windows[curw].front().curwt){
					int curtime=windows[curw].front().curwt;
					windows[curw].push(list.front());
					last.push(windows[curw].front());
					windows[curw].pop();
					list.pop();
					if(windows[curw].front().t<curtime){
						windows[curw].front().wait=curtime-windows[curw].front().t;
						windows[curw].front().waitstate=1;
						windows[curw].front().curwt=curtime+windows[curw].front().p;
					}else if(windows[curw].front().t>=curtime){
						curtime=windows[curw].front().t;
						windows[curw].front().curwt=curtime+windows[curw].front().p;
					}
					break; 
				}
			}
			curw++;
		}
	}
	int curw=0,maxt=0;
	while(curw<w){
		if(windows[curw].size()){
			if(maxt<windows[curw].front().curwt){
				maxt=windows[curw].front().curwt; 
			}
		}
		curw++;
	}
	int maxwait=0;
	double avet=0;
	queue<people>temp=last;
	while(temp.size()){
		if(temp.front().waitstate==1){
			avet+=temp.front().wait;
			if(maxwait<temp.front().wait){
				maxwait=temp.front().wait;
			} 
		}
		temp.pop();
	}
	curw=0;
	while(curw<w){
		if(!windows[curw].empty()){
			if(windows[curw].front().waitstate==1){
				avet+=windows[curw].front().wait;
				if(maxwait<windows[curw].front().wait){
					maxwait=windows[curw].front().wait;
				}
			}
		}
		curw++;
	}
	cout<<fixed<<setprecision(1)<<avet/n<<" "<<maxwait<<" "<<maxt<<endl;
}
