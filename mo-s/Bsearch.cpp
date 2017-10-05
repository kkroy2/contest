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
//ios_base::sync_with_stdio(false);cin.tie(NULL);
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
int a[N];
bool binarysearch(int a, int target)
{
    int lo = 1, hi = A.size();
    while (lo <= hi)
    {
        mid = lo + (hi-lo)/2;
        if (A[mid] == target)
            return true;
        else if (A[mid] < target)
            lo = mid+1;
        else
            hi = mid-1;
    }
    return false;
}
double hi=1,lo=0,l,r;
        int k=64;
        while(k--)
        {
            r=lo+2*(hi-lo)/3;
            l=lo+(hi-lo)/3;
            //cout<<r<<" "<<l<<endl;
            //cout<<dist(a*l,b*l)<<" "<<dist(a*r,b*r)<<endl;
            if(l<((double)1)/1e9)break;
            if(dist(div(l,aa,a),div(l,c,b))<dist(div(r,aa,a),div(r,c,b)))hi=r;
            else lo=l;
        }
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cout.flush();
    //freopen("out.txt","w",stdout);
    int a[] = {19,19,19,30,30,31,31,31};
    sort (a,a+8);
    int low=lower_bound (a, a+8, 32)-a;
    int high=upper_bound (a, a+8, 32)-a;
    //cout<<low<<" "<<high<<endl;

    return 0;
}
