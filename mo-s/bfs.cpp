//bfs basic
vector<int> adj[40];
bool vis[40];
int level[40];
int parent[50];
//s starting node, n no of nodes
void bfs(int s)
{
    int i;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    queue<int> q;

    q.push(s);
    vis[s] = true;
    level[s] = 0;
    parent[s] = s; //needed for path printing
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(i=0; i<adj[u].size(); i++)
        {
            if(!vis[adj[u][i]])
            {
                int v = adj[u][i];
                vis[v] = true;
                q.push(v);
                level[v] = level[u] + 1;
                parent[v] = u;
            }
        }

    }
}

//bfs path printing
void pathf(int s)
{
    if(s==parent[s]) return;
    pathf(parent[s]);
    cout<<parent[s]<<" "<<s<<endl;
}

//bfs 2D grid
#define pii pair<int,int>
#define valid(nx,ny) nx>='a' && nx<='h' && ny>=1 && ny<=8
int fx[]={1,-1,0,0}; //ডিরেকশন অ্যারে
int fy[]={0,0,1,-1};
int cell[100][100]; //cell[x][y] যদি -১ হয় তাহলে সেলটা ব্লক
int d[100][100],vis[100][100]; //d means destination from source.
int row,col;
void bfs(int sx,int sy) //Source node is in [sx][sy] cell.
{
	memset(vis,0,sizeof vis);
	vis[sx][sy]=1;
	queue<pii>q; //A queue containing STL pairs
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front(); q.pop();
		for(int k=0;k<4;k++)
		{
			int tx=top.uu+fx[k];
			int ty=top.vv+fy[k]; //Neighbor cell [tx][ty]
			if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0) //Check if the neighbor is valid and not visited before.
			{
				vis[tx][ty]=1;
				d[tx][ty]=d[top.uu][top.vv]+1;
				q.push(pii(tx,ty)); //Pushing a new pair in the queue
			}
		}
	}
}

//Bicoloring
bool vis[230];
vector<int> adj[100000];
int color[10000];

bool bfs(int s)
{
    int i;
    memset(vis,false,sizeof(vis));
    memset(color,'z',sizeof(color));
    queue<int> q;
    q.push(s);
    color[s] = 'r';
    vis[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        //color[u] = 'r';
        for(int i = 0; i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(vis[adj[u][i]])
            {
                if(color[v]==color[u]) return false;
            }
            if(!vis[adj[u][i]])
            {
                if(color[u]=='r')color[v] = 'b';
                else color[v] = 'r';
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return true;
}

