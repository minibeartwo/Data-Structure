#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // 预定义数据对，first为结点与起点距离，second为结点编号
const int maxn = 110;
int t, n;
int g[maxn][maxn];  // 图
int last[maxn];     // 最短路“上一个”结点
int dis[maxn];      // 结点与起点的动态更新的距离
char buf[20];       // 字符串输入缓存
int start;          // 起点
void Dijkstra(int start)
{
    // 此处 相对 “priority_queue<pii> q;” 的常规写法来说：
    // “, vector<pii>, greater<pii> ” 用于让优先队列构建大顶堆，从而每次出队为最小值
    priority_queue<pii, vector<pii>, greater<pii> > q;
    for(int i=0;i<n;i++)dis[i]=0x3f3f3f3f;
    dis[start]=0;
    q.push({0,start});
    last[start]=-1;
    // TODO: 初始化dis[start]， 起点与起点的距离为0
    // TODO: 起点放入优先级队列
    // TODO: 记录路径，起点的“上一个”为空
    while(!q.empty())
    {
        pii now = q.top();  // 优先级队列队顶用“top”而不用“front”
        q.pop();            // 出队
		// 如果出队结点记录的距离不是最新的距离，则丢弃该出队结点
        if(now.first != dis[now.second]) continue; 
        for(int i = 0; i < n; i ++)
        {
        	if(g[now.second][i]&&dis[i]>dis[now.second]+g[now.second][i]){
        		dis[i]=now.first+g[now.second][i];
        		last[i]=now.second;
        		q.push({dis[i],i});
			}
            // TODO: 对每个与 now.second 相连接的结点，看是否能更新该结点与起点的距离
            // 能更新则更新后将该结点入队
            // 更新 last[i]，i结点在最短路中的“上一个”
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
	// TODO: 利用last信息输出路径
    // dis 为无穷（0x3f3f3f3f）的结点表示未连通
}
int main()
{
    for(scanf("%d", &t); t --; )
    {
        map<int, string> mpNode;    // 记录编号与名称的对应
        map<string, int> mpId;      // 记录名称与编号的对应
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
        {
        	cin>>buf;
        	mpNode[i]=buf;
        	mpId[buf]=i;
            // TODO: 用buf读入名称字符串
            // 用mpNode和mpId记录对应关系
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++)cin>>g[i][j];
		}
		cin>>buf;
		start=mpId[buf];
        // TODO: 读入图
        // TODO: 读入起点名称字符串
        // TODO: 利用mpId将起点名称转换为起点编号赋值给start
        Dijkstra(start);
        Output(start, mpNode);
    }
    return 0;
}
