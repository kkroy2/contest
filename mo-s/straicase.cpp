#include<bits/stdc++.h>
using namespace std;

long long dp[1000][1000];
int n;
long long stc(int last, int remain)
{

    if(remain==0) return 1;
    if(remain<=last) return 0;
    if(dp[last][remain]!=-1) return dp[last][remain];
    long long ret = 0;
    for(int i=last+1;i<=remain;i++)
    {
        ret += stc(i,remain-i);

    }
    return dp[last][remain] = ret;

}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cout<<stc(0,n) - 1<<endl;

    return 0;
}
