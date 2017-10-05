#include<bits/stdc++.h>
using namespace std;

int w[105],b[105];
int main()
{
    int t,n,x=0,cs=1 ;
    cin>>t;
    while(t--)
    {
        x = 0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>w[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++)
        {
            x ^= (abs(w[i] - b[i]) - 1);
        }

        if(x)cout<<"Case "<<cs++<<": white wins"<<endl;
         else cout<<"Case "<<cs++<<": black wins"<<endl;

    }
    return 0;
}

