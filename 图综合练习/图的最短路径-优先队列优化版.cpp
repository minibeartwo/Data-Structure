#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // Ԥ�������ݶԣ�firstΪ����������룬secondΪ�����
const int maxn = 110;
int t, n;
int g[maxn][maxn];  // ͼ
int last[maxn];     // ���·����һ�������
int dis[maxn];      // ��������Ķ�̬���µľ���
char buf[20];       // �ַ������뻺��
int start;          // ���
void Dijkstra(int start)
{
    // �˴� ��� ��priority_queue<pii> q;�� �ĳ���д����˵��
    // ��, vector<pii>, greater<pii> �� ���������ȶ��й����󶥶ѣ��Ӷ�ÿ�γ���Ϊ��Сֵ
    priority_queue<pii, vector<pii>, greater<pii> > q;
    for(int i=0;i<n;i++)dis[i]=0x3f3f3f3f;
    dis[start]=0;
    q.push({0,start});
    last[start]=-1;
    // TODO: ��ʼ��dis[start]�� ��������ľ���Ϊ0
    // TODO: ���������ȼ�����
    // TODO: ��¼·�������ġ���һ����Ϊ��
    while(!q.empty())
    {
        pii now = q.top();  // ���ȼ����жӶ��á�top�������á�front��
        q.pop();            // ����
		// ������ӽ���¼�ľ��벻�����µľ��룬�����ó��ӽ��
        if(now.first != dis[now.second]) continue; 
        for(int i = 0; i < n; i ++)
        {
        	if(g[now.second][i]&&dis[i]>dis[now.second]+g[now.second][i]){
        		dis[i]=now.first+g[now.second][i];
        		last[i]=now.second;
        		q.push({dis[i],i});
			}
            // TODO: ��ÿ���� now.second �����ӵĽ�㣬���Ƿ��ܸ��¸ý�������ľ���
            // �ܸ�������º󽫸ý�����
            // ���� last[i]��i��������·�еġ���һ����
        }
    }
}
void Output(int start, map<int,string> &mpNode)
{
    for(int i=0;i<n;i++){
    	if(i==start)continue;
    	cout<<mpNode[start]<<"-"<<mpNode[i];
    	if(dis[i]==0x3f3f3f3f){
    		cout<<"--1"<<endl;
		}else{
			cout<<"-"<<dis[i]<<"----[";
			int x=i;
			stack<int>s;
			while(last[x]!=-1){
				s.push(last[x]);
				x=last[x];
			}
			while(s.size()){
				cout<<mpNode[s.top()]<<" ";
				s.pop();
			}
			cout<<mpNode[i]<<" ]"<<endl;
		}
	}
	// TODO: ����last��Ϣ���·��
    // dis Ϊ���0x3f3f3f3f���Ľ���ʾδ��ͨ
}
int main()
{
    for(scanf("%d", &t); t --; )
    {
        map<int, string> mpNode;    // ��¼��������ƵĶ�Ӧ
        map<string, int> mpId;      // ��¼�������ŵĶ�Ӧ
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
        {
        	cin>>buf;
        	mpNode[i]=buf;
        	mpId[buf]=i;
            // TODO: ��buf���������ַ���
            // ��mpNode��mpId��¼��Ӧ��ϵ
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++)cin>>g[i][j];
		}
		cin>>buf;
		start=mpId[buf];
        // TODO: ����ͼ
        // TODO: ������������ַ���
        // TODO: ����mpId���������ת��Ϊ����Ÿ�ֵ��start
        Dijkstra(start);
        Output(start, mpNode);
    }
    return 0;
}
