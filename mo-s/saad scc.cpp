#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
#define enl cout<<endl
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;

const int mx=1e5+10;

int n, m;
vector<int> adj[mx];
vector<int> rev_adj[mx];

stack<int> S;
bool visited[mx];

int component[mx];
vector<int> components[mx];
int numComponents;

void kosaraju_dfs_1(int x)
{
    visited[x] = true;
    for (int i=0;i<graf[x].adj.size();i++)
    {
        if (!visited[graf[x].adj[i]]) kosaraju_dfs_1(graf[x].adj[i]);
    }
    S.push(x);
}

void kosaraju_dfs_2(int x)
{
    printf("%d ", x);
    component[x] = numComponents;
    components[numComponents].push_back(x);
    visited[x] = true;
    for (int i=0;i<graf[x].rev_adj.size();i++)
    {
        if (!visited[graf[x].rev_adj[i]]) kosaraju_dfs_2(graf[x].rev_adj[i]);
    }
}

void Kosaraju()
{
    for (int i=0;i<n;i++)
    {
        if (!visited[i]) kosaraju_dfs_1(i);
    }
    
    for (int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    
    while (!S.empty())
    {
        int v = S.top(); S.pop();
        if (!visited[v])
        {
            printf("Component %d: ", numComponents);
            kosaraju_dfs_2(v);
            numComponents++;
            printf("\n");
        }
    }
}

int main()
{
    Kosaraju();   
    printf("Total number of components: %d\n", numComponents);
    return 0;
}
