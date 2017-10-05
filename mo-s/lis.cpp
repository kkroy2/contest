#include<bits/stdc++.h>
using namespace std;

int way[10000];
int a[10000];
int path[10000];

int lis(int n)
{
    int mx=0;
    for (int i=0;i<n;i++) way[i] = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j]) way[i] = max(way[i],way[j]+1);
        }
    }
    for(int i=0;i<n;i++) mx = max(way[i],mx);
    int j=0;
    int temp = mx;
    for(int i=n-1;i>=0;i--)
    {
        if(way[i]==temp)
        {
            path[j++] = a[i];
            temp--;
        }
    }
    return mx;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<lis(n)<<endl;

    for(int i=0;i<lis(n);i++) cout<<path[i]<<" ";
    return 0;
}
