#include<bits/stdc++.h>
using namespace std;
double f[10000];
int main()
{
    int n,i;
    int  ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
       f[i] = log10(i) + f[i-1];
    }
    //double l = f[10] - f[9];
    ans=f[n] + 1;
    //ans++;
    printf("%d\n",ans);
    return 0;
}
