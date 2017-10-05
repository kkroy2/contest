#include<bits/stdc++.h>
using namespace std;

struct node
{
    long long now, cost;
    node (){}
    node(long long _now, long long _cost)
    {
        now = _now ;
        cost = _cost ;
    }
};

struct edge
{
    long long v, w;
    edge(){}
    edge(long _v, long _w)
    {
        v = _v;
        w = _w;
    }
};

bool operator <(node a, node b)
{
    return a.cost>b.cost;
}
vector<edge>adj[100006];
long long dis[100006];
priority_queue<node> pq;
long long parent[100006];
void dijkstra(long long s)
{
    int i,j;
    for(i=0;i<100006;i++) dis[i] = INT_MAX;
    dis[s] = 0;
    parent[s] = s;
    pq.push(node(s,0));
    while(!pq.empty())
    {
        node u = pq.top();
        pq.pop();
        if(u.cost!=dis[u.now]) continue;
        for(i=0;i<adj[u.now].size();i++)
        {
            edge e = adj[u.now][i];
            if(dis[e.v]> u.cost + e.w)
            {
                dis[e.v] = u.cost + e.w;
                pq.push(node(e.v,dis[e.v]));
                parent[e.v] = u.now;
               // printf("%d %d\n",e.v,dis[e.v]);
            }

        }
    }
}

void pathf(long long s)
{
    if(s==parent[s])
    {
        cout<<s;
        return;
    }
    pathf(parent[s]);
    cout<<" "<<s;
}

int main()
{

    int s = -1;

    cout<<(char)s<<endl;

    cout<<s<<endl;
    long long m,n,a,b,w,i,j;
    //scanf("%d %d",&n,&m);
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        //scanf("%d %d %d",&a,&b,&w);
        adj[a].push_back(edge(b,w));
        adj[b].push_back(edge(a,w));
    }
    dijkstra(1);
    cout<<dis[n]<<endl;
    if(dis[n]== INT_MAX) cout<<-1<<endl;
    else
    {
        pathf(n);
        cout<<endl;
    }

    printf("%d\n", dis[n]);
    return 0;
}
