#include<bits/stdc++.h>
using namespace std;
long long dp[22][22];

long long solve(int m, int n,int a, int b)
{
    if(m==0 || n==0) return 1;
    if(m==a && n==b) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    else
    {
        dp[m][n] = solve(m,n-1,a,b) + solve(m-1,n,a,b) + solve(m-1,n-1,a,b);
        return dp[m][n];
    }
}
int main()
{
    int n,t,m,a,b;
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&m,&n,&a,&b);
    printf("%lld\n",solve(m,n,a,b));
    return 0;

}
