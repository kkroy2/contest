#include<bits/stdc++.h>
using namespace std;

int tmar[55][55] ,tlar[55][55];
 long long int mx = 999999999999999;
typedef pair< long long int ,long long int > pii;

pii dp[55][1005];
int n , tim;
pii pmin(pii a  , pii b)
{
    if(a.first < b.first)
        return a;
    else if( b.first < a.first)
        return b;
    else
    {
        if(a.second < b.second)
            return a;
        else
            return b;
    }
}
pii solve(int pos , int usedt)
{
    //cout<<pos<<" "<<usedt<<endl;
    if(usedt  > tim)
    {
        pii ret;
        ret.first = mx;
        ret.second = usedt;
        return ret;
    }
    if(pos == n-1)
    {
        pii ret;
        ret.first = tlar[pos][pos];
        ret.second = usedt;
        return ret ;
    }
    if(dp[pos][usedt].first !=-1)
    {
        return dp[pos][usedt];
    }
    pii p = make_pair(mx , tim);
    for(int i = n-1; i >= 0; i--)
    {
        if(pos==i)
            continue;
         //   cout<<tmar[pos][i]<<endl;
        pii q = solve(i , usedt + tmar[pos][i]);
        q.first += tlar[pos][i];
        p = pmin( p , q);
    }
    return dp[pos][usedt] = p;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(cin>>n&&cin>>tim&&n&&tim)
    {
        memset(dp , -1 , sizeof(dp));
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                cin>>tmar[i][j];
            }
        }

        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                cin>>tlar[i][j];
            }
        }
        pii res = solve(0 , 0);
        cout<<res.first<<" "<<res.second<<endl;
    }
    return 0;
}
