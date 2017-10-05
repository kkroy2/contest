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
typedef priority_queue<PI,vector<PI>,greater<PI>> Minheap;
const long long int N=1e5+7;
struct point
{
    int a,b;
    point () {}
    point(int _a,int _b)
    {
        a=_a;
        b=_b;
    }
};
bool operator<(point a,point b)
{
    if(a.a==b.a)return a.b<b.b;
    return a.a<b.a;
}
//----------------------------------------------------------------------------------------------------------------------------------------//
//__builtin_popcount (int)
//__builtin_popcountll (long long int)
bool Check(int n,int pos)
{
    return (bool)(n & (1<<pos));
}
int Set(int n,int pos)
{
    return n=n | (1<<pos);
}
int reset(int n,int pos)
{
    return n=n & ~(1<<pos);
}
unsigned long long arr[N];
unsigned long long  pairor(int n)
{
    unsigned long long one=1,k;
    rept(i,0,n)cin>>arr[i];
    for (int i = 0; i < 32; i++)
    {
        k = 0;
        for (int j = 0; j < n; j++)
            {if ( (arr[j] & (one << i)) )k++;one=1;}
        m+=((1<<i)*((k*(k-1)/2)+((n-k)*k))) ;
    }
    n=(n*(n-1))/2;
    k=gcd(m,n);
    printf("%lld/%lld\n",m/k,n/k);
    return m;
}
unsigned long long  pairand(int n)
{
    unsigned long long one=1,k;
    rept(i,0,n)cin>>arr[i];
    for (int i = 0; i < 32; i++)
    {
        k = 0;
        for (int j = 0; j < n; j++)
            {if ( (arr[j] & (one << i)) )k++;one=1;}
        m+=((1<<i)*((k*(k-1)/2)) ;
    }
    n=(n*(n-1))/2;
    k=gcd(m,n);
    printf("%lld/%lld\n",m/k,n/k);
    return m;
}
