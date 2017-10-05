#include<bits/stdc++.h>
using namespace std;
const int p=13;
int ncr[p+1][p+1];
int nCrModpDP(int n, int r, int p)
{
    int C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}
int ncrpre(int n)
{
    ncr[0][0]=1
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(j>i)ncr[i][j]=0;
            else if(j==i || j==0)n[i][j]=1
            else ncr[i][j]=(ncr[i-1][j-1]%p+ncr[i-1][j]%p)%p
        }
    }
}
int nCrModpLucas(int n, int r, int p)
{
   if (r==0)
      return 1;
   int ni = n%p, ri = r%p;
   return (nCrModpLucas(n/p, r/p, p)%p * ncr[ni][ri]%p) % p;
}
ll ncr(int n, int r)
{
    ll ans=1,rr=1;
    for(int i=n-r+1;i<=n;i++)ans=(ans*i%p)p;
    for(int i=2;i<=n;i++)rr=(rr*i%p)%p;
    rr=big_mod(rr,p-2);
    return (ans*rr)%p;
}
