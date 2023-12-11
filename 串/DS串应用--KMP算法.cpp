#include<iostream>
#include<string>
using namespace std;
class myString
{
private:
    string mainstr; // ´®
    int size;       // ´®³¤¶È
    void GetNext(string p, int next[]);
    int KMPFind(string p, int pos, int next[]);
public:
    myString();
    ~myString();
    void SetVal(string sp);
    int KMPFindSubstr(string p, int pos);
};
void myString::GetNext(string p,int next[]){
	next[0]=-1;
	int j=-1,i=0,len=p.size();
	while(i<len){
		if(j==-1||p[i]==p[j]){
			next[++i]=++j;
		}else{
			j=next[j];
		}
	}
}
int myString::KMPFind(string p,int pos,int next[]){
	int i=0,j=0;
	while(i<mainstr.size()&&j<(int)p.size()){
		if(j==-1||mainstr[i]==p[j]){
			i++;
			j++;
		}else{
			j=next[j];
		}
	}
	if(j==p.size())return i-j+1;
	return 0;
}
myString::myString()
{
    size = 0;
    mainstr = "";
}
myString::~myString()
{
    size = 0;
    mainstr = "";
}
void myString::SetVal(string sp)
{
    mainstr = "";
    mainstr.assign(sp);
    size = mainstr.length();
}
int myString::KMPFindSubstr(string p, int pos)
{
    int i;
    int L = p.length();
    int *next = new int[L+1];
    GetNext(p, next);
    for(i = 0; i < L; i ++)
        cout << next[i] << ' ';
    cout << endl;
    int v = -1;
    v = KMPFind(p, pos, next);
    delete []next;
    return v;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		myString a;
		string b,c;
		cin>>b>>c;
		a.SetVal(b);
		int ans=a.KMPFindSubstr(c,0);
		cout<<ans<<endl;
	}
}
