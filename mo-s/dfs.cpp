#include<bits/stdc++.h>
#define MAX_N 5001
using namespace std;
typedef long long lld;

vector<int>adj[MAX_N];
bool mark[MAX_N];
bool vis[MAX_N];
inline void DFS(int start)//iterative
{
    stack<int> dfs_stek;
    dfs_stek.push(start);
    memset(mark,false,sizeof mark);
    while (!dfs_stek.empty())
    {
        int xt = dfs_stek.top();
        dfs_stek.pop();
        mark[xt] = true;
        printf("Traversing Node ID %d\n", xt);
        for (int i=0; i<adj[xt].size(); i++)
        {
            if (!mark[adj[xt][i]])
            {
                dfs_stek.push(adj[xt][i]);
                mark[adj[xt][i]] = true;
            }
        }
    }
}
void dfss(int n)//recursive
{
    vis[n]=true;
    printf("Traversing Node ID %d\n", n);
    for (int i=0; i<adj[n].size(); i++)
    {
        if (!vis[adj[n][i]])
        {
            dfss(adj[n][i]);
        }
    }
}
void dfst(int n,int par)//if tree means no cycle
{
    printf("Traversing Node ID %d\n", n);
    for (int i=0; i<adj[n].size(); i++)
    {
        if (adj[n][i]!=par)
        {
            dfst(adj[n][i],n);
        }
    }
}
int main()
{
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    //iterative dfs
    DFS(0);
    memset(vis,false,sizeof vis);
    cout<<endl<<endl;
    //recursive dfs
    dfss(0);
    cout<<endl<<endl;
    cout<<endl<<endl;
    //dfs on tree. this example graph is a tree
    dfst(0,-1);
    return 0;
}
