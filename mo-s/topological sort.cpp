#include<bits/stdc++.h>
using namespace std;

//using dfs - end time ke decreasing order e
vector<int>adj[1000];
bool vis[100];
int timee;
int start[100];
vector<pair<int,int>>endi;
void dfss(int n)//recursive
{
    vis[n]=true;
    timee++;
    start[n] = timee;
    for (int i=0; i<adj[n].size(); i++)
    {
        if (!vis[adj[n][i]])
        {
            dfss(adj[n][i]);
        }
    }
    timee++;
    endi.push_back(make_pair(timee,n));
}

//using in degree, outdegree
const int mx=2e4+10;
int ind[mx];
//vector<int>adj[mx];
void topo()
{
    int n,id=1;
    memset(ind,0,sizeof(ind));
    queue<int>ans;
    queue<int>temp;
    for(int i=0;i<=5;i++)if(!ind[i])temp.push(i);
    while(!temp.empty())
    {
        int v=temp.front();
        cout<<v<<" ffffdsfef"<<endl;
        temp.pop();
        ans.push(v);
        for(int i=0;i<adj[v].size();i++)
        {
            ind[adj[v][i]]--;
            if(ind[adj[v][i]]==0)
            {
                temp.push(adj[v][i]);
            }
        }
    }
    while(!ans.empty())
    {
        cout<<ans.front()<<endl;
        ans.pop();
    }

}
int main()
{
    adj[0].push_back(1);
    ind[1]++;
    adj[0].push_back(2);
    ind[2]++;
    adj[2].push_back(3);
    ind[3]++;
    adj[3].push_back(4);
    ind[4]++;
    adj[4].push_back(5);
    ind[5]++;

    topo();
    dfss(0);
    sort(endi.begin(), endi.end());
    for(int i=5;i>=0;i--)
    {
        cout<<endi[i].second<<" ";
    }

    return 0;
}
