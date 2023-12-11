#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double num;
        cin>>num;
        int k;
        cin>>k;
        int a = (int)num;
        double b = num-a;
        stack<int> numint;
        queue<int> numdou;
        while(a)
        {
            numint.push(a%k);
            a = a/k;
        }
        int temp = 3;
        while(temp--)
        {
            numdou.push((int)(b*k));
            b = b*k-(int)(b*k);
        }
        char letter[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
        while(!numint.empty())
        {
            if(numint.top()<10)
                cout<<numint.top();
            else
                cout<<letter[numint.top()-10];
            numint.pop();
        }
        cout<<'.';
        while(!numdou.empty())
        {
            if(numdou.front()<10)
                cout<<numdou.front();
            else
                cout<<letter[numdou.front()-10];
            numdou.pop();
        }
        cout<<endl;
    }
    return 0;
}
