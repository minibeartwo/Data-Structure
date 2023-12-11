#include <bits/stdc++.h>
using namespace std;
class animal{
	public:
		queue<int>cat;
		queue<int>dog;
		animal(){}
		void enqueue(){
			int order;
			string type;
			cin>>order>>type;
			if(type=="cat"){
				cat.push(order);
			}else{
				dog.push(order);
			}
		}
		void dequeueany(){
			if(cat.empty()&&dog.empty()){
				cout<<"[-1 none] ";
				return;
			}
			if(cat.empty()){
				cout<<"["<<dog.front()<<" dog] ";
				dog.pop();
				return;
			}
			if(dog.empty()){
				cout<<"["<<cat.front()<<" cat] ";
				cat.pop();
				return;
			}
			if(cat.front()<dog.front()){
				cout<<"["<<cat.front()<<" cat] ";
				cat.pop();
			}else{
				cout<<"["<<dog.front()<<" dog] ";
				dog.pop();
			}
		}
		void dequeuedog(){
			if(dog.empty()){
				cout<<"[-1 none] ";
				return;
			}else{
				cout<<"["<<dog.front()<<" dog] ";
				dog.pop();
				return;
			}
		}
		void dequeuecat(){
			if(cat.empty()){
				cout<<"[-1 none] ";
				return;
			}else{
				cout<<"["<<cat.front()<<" cat] ";
				cat.pop();
				return;
			}
		}
};
int main(){
	int t,n;
	cin>>t;

	while(t--){
		cin>>n;
		animal b;
		while(n--){
			
			string a;
			cin>>a;
			if(a=="enqueue"){
				b.enqueue();
			}else if(a=="dequeueCat"){
				b.dequeuecat();
			}else if(a=="dequeueDog"){
				b.dequeuedog();
			}else if(a=="dequeueAny"){
				b.dequeueany();
			}
		}
		cout<<endl;
	}
}
