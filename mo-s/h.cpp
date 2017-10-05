#include<bits/stdc++.h>
using namespace std;
int vis[111][111];

int grundy_number(int n,int m)
{
    if(m<=0 || n<=0) return 0;
    if(vis[n][m]==-1)
    {
        int s[200];
        memset(s,0,sizeof s);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                s[grundy_number(i-1,j-1)^grundy_number(i-1,m-j)^grundy_number(n-i,j-1)^grundy_number(n-i,m-j)]=1;
            }
        }
        int ans=0;
        while(s[ans])ans++;
        return vis[n][m] = ans;

    }
    else return vis[n][m];
}
int main()
{
    int t,cs=1;
    memset(vis,-1,sizeof(vis));
    vis[0][0]=0;
    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=100; j++) grundy_number(i,j);
    }
    cin>>t;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        int x = vis[r][c];
        if(x) cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}
