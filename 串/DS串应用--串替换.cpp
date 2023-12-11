#include <iostream>
#include <string>
using namespace std;

void Next(string s,int *net)
{
   int i=0,j=-1; 
   
   net[0]=-1; 
   while(i<s.length()) 
   {
       if(j==-1||s[i]==s[j]) 
       {
           i++;
           j++;
           net[i]=j; 
       }
       else
       {
           j=net[j];  
       }
   }
}
int KMP(string s,string t) 
{
   int i=0,j=0;
   int len=s.length();
   int len2=t.length();
   int *net=new int [t.length()+1];
   Next(t,net);
   while(i<len&&j<len2) 
   {
       if(j==-1||s[i]==t[j]) 
       {
           i++;
           j++;
       }
       else 
       {
           j=net[j];
       }
   }
   if(j==len2) 
   {
       return i-j; 
   }
   else
       return -1;
}

int main(void)
{
   int n;
   cin>>n;
   while(n--)
   {
       string s;
       cin>>s;
       cout<<s<<endl;
       string a;
       string b;
       cin>>a;
       cin>>b;
       int k;
       k=KMP(s,a);
       if(k!=-1)
       {
           s.replace(k,a.length(),b);
       }
       cout<<s<<endl;
   }
   return 0;
}
