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
struct Node{
    ll x,lazy,sz;
    Node()
    {
        x=lazy=sz=0;
    }
    void clear()
    {
        x=lazy=sz=0;
    }
    void Merge(Node l,Node r)
    {
        x=l.x+r.x;
        sz=l.sz+r.sz;
    }

};
Node tree[mx*4];
int arr[mx];
void build(int node,int s,int e)
{
    if(s>e)return;
    if(s==e)
    {
       tree[node].x=arr[s];
       tree[node].lazy=0;
       tree[node].sz=1;
       return;
    }
    int mid=s+(e-s)/2;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    tree[node].Merge(tree[node*2],tree[node*2+1]);
}
void pushdown(int idx)
{
    if(tree[idx].lazy==0)return;
    tree[idx*2].x+=tree[idx].lazy*tree[idx*2].sz;
    tree[idx*2+1].x+=tree[idx].lazy*tree[idx*2+1].sz;
    tree[idx*2].lazy+=tree[idx].lazy;
    tree[idx*2+1].lazy+=tree[idx].lazy;
    tree[idx].lazy=0;
}

void update(int node,int s,int e,int l,int r,int v)
{
    if(l>r)return;
    if(l<=s && e<=r)
    {
        tree[node].x+=tree[node].sz*v;
        tree[node].lazy+=v;
        return;
    }
    pushdown(node);
    int mid=s+(e-s)/2;
    if(l<=mid)update(node*2,s,mid,l,min(mid,r),v);
    if(r>mid)update(node*2+1,mid+1,e,max(mid+1,l),r,v);
    tree[node].Merge(tree[node*2],tree[node*2+1]);
}


ll query(int node,int s,int e,int l,int r)
{
    if(l>r)return 0;
    if(l<=s && e<=r)
    {
        return tree[node].x;
    }
    pushdown(node);
    int mid=s+(e-s)/2;
    ll ans=0;
    if(l<=mid)ans+=query(node*2,s,mid,l,min(mid,r));
    if(r>mid)ans+=query(node*2+1,mid+1,e,max(mid+1,l),r);
    return ans;
}

