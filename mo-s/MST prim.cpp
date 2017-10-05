#include<bits//stdc++.h>
using namespace std;
int visited[1000]={0};
vector<int>edge[1000];
vector<int>cost[1000];
struct data
{  int v,w;
    bool operator < ( data p ) const {
        return w > p.w;
    }
};
int Prims(int src,int n)
{
    priority_queue<data>pq;
    int i,u,v,sum=0,j,p;
    for(i=0;i<n-1;i++)
    {
        u=src;
        visited[src]=1;

        for(j=0;j<edge[u].size();j++)
        {
            v=edge[u][j];
            if(visited[v]==0)
            {
                data D; D.v=v;
                D.w=cost[u][j];
                pq.push(D);
            }
        }
        while(visited[src]){
        data T=pq.top();pq.pop();
        src=T.v;p=T.w;
        }
        sum+=p;
        }
        return sum;
}
int main()
{

    scanf("%d %d",&n,&e);
    for(i=0;i<e;i++)
    {
        scanf("%d %d %d",&n1,&n2,&w);
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
        cost[n1].push_back(w);
        cost[n2].push_back(w);
    }
    printf("%d\n",Prims(1,n));
    return 0;
}
