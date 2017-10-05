#include<bits/stdc++.h>
using namespace std;

int dp[10006];
int grundy_number(int cur)
{
    if(dp[cur]==-1)
    {
        int s[10004];
        memset(s,0,sizeof s);
        for(int i=1; i<=cur/2; i++)
        {
            if(i==(cur-i)) continue;
            s[(grundy_number(cur-i) ^ grundy_number(i))]++;
        }
        int ans=0;
        while(s[ans])ans++;
        return dp[cur] = ans;
    }
    else return  dp[cur];
}
int main()
{
    int t,n,a,cs=1;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;dp[1]=0;dp[2]=0;dp[3]=1;
    for(int i=4;i<=10000;i++){grundy_number(i);}
    cin>>t;
    while(t--)
    {
        cin>>n;
        int x = 0;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            x^=dp[a];
        }
        if(x) cout<<"Case "<<cs++<<": Alice"<<endl;
        else cout<<"Case "<<cs++<<": Bob"<<endl;
    }
    return 0;
}

