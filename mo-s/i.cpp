#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,a[1010],d[1010],x=0,i;
    cin>>t;
    while(t--)
    {
        x=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
           cin>>a[i];
        }
        sort(a,a+n);
        if(n%2)
        x = a[0]-1;
       // cout<<x<<endl;
        //int j=n-1;

        if(n%2==0) i =0;
        else i = 1;
        // if(n%2) cout<<x;
        for(;i<n;i+=2)
        {
            x^= a[i+1] - a[i] - 1;
        }
       // cout<<x<<endl;
        if(x) cout<<"Georgia will win"<<endl;
        else cout<<"Bob will win"<<endl;
    }

    return 0;
}

