#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;
PI adj[55][55];
int vis[55][1012];
void bfs(int n,int t)
{
    memset(vis,-1,sizeof(vis));
    priority_queue <PII> q;
    PII s=make_pair(make_pair(1,0),0);
    q.push(s);
    vis[1][0] = 0;
    while(!q.empty())
    {
        int node = q.top().first.first;
        int cost = q.top().first.second;
        int time = q.top().second;
        q.pop();
        for(int i = 1;i <= n ; i++)
        {
            if(i==node)continue;
            if(adj[node][i].first+time>t)continue;
            if(vis[i][adj[node][i].first+time] == -1)
            {
                vis[i][adj[node][i].first+time]=cost+adj[node][i].second;
                q.push(make_pair(make_pair(i,vis[i][adj[node][i].first+time]),adj[node][i].first+time));
            }
            else if(vis[i][adj[node][i].first+time]>cost+adj[node][i].second)
            {
                vis[i][adj[node][i].first+time]=cost+adj[node][i].second;
                q.push(make_pair(make_pair(i,vis[i][adj[node][i].first+time]),adj[node][i].first+time));
            }
        }
    }

}
int main()
{
    while(1)
    {
        int n,t;
        cin>>n>>t;
        if(n==0 && t==0)break;
        rept(i,1,n+1)
        {
            rept(j,1,n+1)
            {
                cin>>adj[i][j].first;
            }
        }
        rept(i,1,n+1)
        {
            rept(j,1,n+1)
            {
                cin>>adj[i][j].second;
            }
        }
        int ac=INT_MAX;
        int aat=0;
        bfs(n,t);
        for(int i=0;i<=t;i++)
        {
            if(vis[n][i]!=-1 && vis[n][i]<ac)
            {
                ac=vis[n][i];
                aat=i;
            }
        }
        cout<<ac<<" "<<aat<<endl;
    }
    return 0;
}
