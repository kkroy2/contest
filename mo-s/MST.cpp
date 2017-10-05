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
const long long int N=1e5+7;
struct edge{
    int u,v,w;
    edge (){}
    edge(int _u,int _v,int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }
};
bool operator<(edge a,edge b){return a.w<b.w;}
//----------------------------------------------------------------------------------------------------------------------------------------//
const int maxunion=1e5+10;
int parent[maxunion],szunion[maxunion];
void initialize()
{
    rept(i,0,maxunion)
    {
        parent[ i ] = i ;
        szunion[ i ] = 1;
    }
}
int root (int i)
{
    while(parent[ i ] != i)
    {
        parent[ i ] = parent[ parent[ i ] ] ;
        i = parent[ i ];
    }
    return i;
}
void wunion(int a,int b)
{
    int root_A = root(a);
    int root_B = root(b);
    if(szunion[root_A] < szunion[root_B ])
    {
        parent[ root_A ] = parent[root_B];
        szunion[root_B] += szunion[root_A];
    }
    else
    {
        parent[root_B]=parent[root_A];
        szunion[root_A]+=szunion[root_B];
    }
}
//----------------------------------------------------------------------------------------------------------------//
vector<edge>eee;
int MST()
{
    sort(eee.begin(),eee.end());
    int sz=eee.size(),ans=0;
    rept(i,0,sz)
    {
        if(root(eee[i].u)!=root(eee[i].v))
        {
            ans+=eee[i].w;
            wunion(eee[i].u,eee[i].v);
        }
    }
    return ans;
}
