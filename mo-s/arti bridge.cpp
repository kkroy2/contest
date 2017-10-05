long MAXX 100007
void ini()
{
  int i;
  for(i =0;i<MAXX;i++)
  {
   vis[i]=AP[i]=false; // Initializing AP and vis array as false
   parent[i]=-1;         // Initializing parent of each vertex to -1
   adj[i].clear();        // clearing the adjacency list.
   low[i]=0;

  }
  tim=0;                    // initializing tim to 0
}
vector< pair<int,int> > vec;
void dfs(int u)
{
vis[u]=true;
int  i;
low[u]=disc[u]=(++tim);
int child=0;
  for(i=0;i<adj[u].size();i++)
  {
   int v=adj[u][i];
   if(vis[v]==false)
   {
    child++;
    parent[v]=u;
    dfs(v);

    low[u]=min(low[u],low[v]);
    if ( low[v]>disc[u] ) )
      vec.push_back(make_pair(u,v));

   }
   else if(v!=parent[u])
    {low[u]=min(low[u],disc[v]);}



  }

}
