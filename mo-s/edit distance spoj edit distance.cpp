#include<bits/stdc++.h>
using namespace std;
int res = INT_MAX;
string a,b;
int dp[2020][2020];
int way[2020][2020];
int test;
int disit()
{

        for(int i=0;i<=a.size();i++)
        {
            for(int j=0;j<=b.size();j++)
            {
                if(i==0) way[i][j] = j;

                else if(j==0) way[i][j] = i;

                else if(a[i-1]==b[j-1])
                way[i][j] = way[i-1][j-1];

                else if(a[i-1]!=b[j-1])
                    way[i][j] = 1 + min(way[i-1][j-1], min(way[i][j-1], way[i-1][j]));
                 //   cout<<i<<" "<<j<<""<<way[i][j]<<endl;
            }

        }
        test = way[b.size()][a.size()];
        return way[a.size()][b.size()];
}


/*int dis(int i, int j)
{
    if(i==0) return j;
    if(j==0) return i;
    if(dp[i-1][j-1]==-1)
    {

        if(a[i-1]!=b[j-1])
        {
            res = min(1+dis(i,j-1),(1+dis(i-1,j-1)));
            res = min(res, 1+dis(i-1,j));
            return dp[i][j] = res;
           // return dp[i][j] = min(1+dis(i+1,j), min(1+dis(i,j+1),(1+dis(i+1,j+1))));
        }
        else return dp[i][j]=dis(i-1,j-1);


    }
    else return dp[i][j];


}
*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        res = INT_MAX;
        memset(dp,-1,sizeof(dp));
        cin>>a>>b;

        //cout<<dis(a.size(),b.size()) - 1<<endl;
        cout<<disit()<<endl;
    }
    return 0;
}
