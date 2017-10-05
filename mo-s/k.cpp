#include<bits/stdc++.h>
using namespace std;

int grundy_number(int cur)
{

    //cout<<cur<<" fsfs"<<endl;
    //  vis[cur] = 1;
    if(cur==0) return 0;
    else if(cur==1) return  0;
    else if(cur==2) return  1;
    //  for(int i=0;i<cur;i++)
    //  int moves[] = {cur-1, cur-2};
    set<int>s;
    set<int>::iterator it;
    for(int i=1; i<=cur/2; i++)
    {

        //    if(vis[cur-i]==0)
        s.insert(grundy_number(cur-i));
    }
    int ans = 0;
    for(it=s.begin(); it!=s.end(); it++)
    {
        if(*it==ans) ans++;
        else break;
    }
    // while(s.find(ans)) ans++;
    return  ans;
}
int main()
{
    //for(int i=0;i<=50;i++) cout<<i<<" "<<grundy_number(i)<<endl;
    int t,n,a[1007],cs=1;
    cin>>t;
    while(t--)
    {
        //memset(vis,0,sizeof(vis));
        cin>>n;
        int x = 0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            while(a[i]%2)
            {
                a[i] /= 2;
            }
            x ^= (a[i]/2);
        }
        if(x) cout<<"Case "<<cs++<<": Alice"<<endl;
        else cout<<"Case "<<cs++<<": Bob"<<endl;
    }
    return 0;
}

