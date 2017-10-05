#include<bits/stdc++.h>
using namespace std;
struct node
{

    int att,cost;
    node() {}
    node(int _att,int _cost)
    {
        att=_att;
        cost=_cost;
    }

};
bool operator<(node A, node B)
{
    return A.cost>B.cost;
}
struct edge
{
    int v,w;
    edge() {}
    edge(int _v,int _w)
    {
        v=_v;
        w=_w;
    }
};
const int mx=1e5+10;
vector<edge>adj[mx];
int dis[mx];
priority_queue<node>pq;
const int inf=1e9;
void dijks(int n,int s)
{
    for(int i=0; i<=n; i++)dis[i]=inf;
    while(!pq.empty())pq.pop();
    dis[s]=0;
    pq.push(node(s,0));
    while(!pq.empty())
    {
        node u=pq.top();
        pq.pop();
        if(u.cost !=dis[u.att])continue;
        for(int i=0; i<adj[u.att].size(); i++)
        {
            edge e=adj[u.att][i];
            if( dis[e.v]>u.cost+e.w)
            {
                dis[e.v]=u.cost+e.w;
                pq.push(node(e.v,dis[e.v]));
            }
        }
    }
}

int main()
{
    adj[1].push_back(edge(2,5));
    adj[2].push_back(edge(1,5));
    adj[2].push_back(edge(3,6));
    adj[3].push_back(edge(2,6));
    adj[1].push_back(edge(4,5));
    adj[4].push_back(edge(1,5));
    dijks(4,1);
    for(int i=1;i<=4;i++)cout<<1<<" to "<<i<<" "<<dis[i]<<endl;
    return 0;
}
