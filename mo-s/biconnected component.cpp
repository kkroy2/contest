#include<bits/stdc++.h>
using namespace std;
#define MAXX 100005
stack<pair<int,int> >st;
int vis[MAXX];
vector<int>adj[MAXX];
int low[MAXX], AP[MAXX],parent[MAXX],disc[MAXX];
int tim,noc;
void ini()
{
    int i;
    for(i =0; i<MAXX; i++)
    {
        vis[i]=AP[i]=false;
        parent[i]=-1;
        adj[i].clear();
        low[i]=0;
    }
    tim=0; noc = 0;
//    st.clear();
}

void dfs(int u)
{
    vis[u]=true;
    int  i;
    low[u]=disc[u]=(++tim);
    int child=0;
    for(i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(vis[v]==false)
        {
            child++;
            parent[v]=u;
            st.push(make_pair(u,v));
            dfs(v);

            low[u]=min(low[u],low[v]);
            if( (parent[u]!=-1) and ( low[v]>=disc[u] ) )
            {
                cout<<noc++<<endl;

                pair<int,int> pi = make_pair(u,v);
                while(st.top()!= pi)
                {
                  //  cout<<"nok";
                    cout<<st.top().first<<" "<<st.top().second<<endl;
                    st.pop();
                }
                cout<<st.top().first<<" "<<st.top().second<<endl;
                    st.pop();
               // AP[u]=true;
            }

            if( (parent[u]==-1) && (child>1))
            {
                cout<<noc++<<endl;
                pair<int,int> pi = make_pair(u,v);
                while(st.top()!= pi )
                {
                    //cout<<"ok";
                    cout<<st.top().first<<" "<<st.top().second<<endl;
                    st.pop();
                }
                cout<<st.top().first<<" "<<st.top().second<<endl;
                    st.pop();
            }
                //AP[u]=true;
        }
        else if(v!=parent[u] && low[u]>disc[v])
        {
            low[u] = disc[v];
            st.push(make_pair(u,v));
        }
    }
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;ini();
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
          //  noc++;
        }

    }cout<<noc<<endl;
        while(!st.empty())
        {
            cout<<st.top().first<<" "<<st.top().second<<endl;
                    st.pop();
        }
    return 0;
}
/*
6 6
0 3
3 2
2 5
2 4
1 4
4 5
*/
