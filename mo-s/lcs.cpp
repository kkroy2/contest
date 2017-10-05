#include<bits/stdc++.h>
using namespace std;

string a,b;
int way[10000][10000];

int lcs(int m, int n)
{
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0) way[i][j] = 0;
            else if(a[i-1]==b[j-1]) way[i][j] = 1 + way[i-1][j-1];
            else
            {
                way[i][j] = max(way[i-1][j],way[i][j-1]);
            }
        }
    }
    return way[m][n];
}
char s[10000];
void path_print(int index, int i, int j)
{

    s[index] = '\0';
    index--;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            s[index] = a[i-1];
            i--;
            j--;
            index--;
        }
        else if(way[i-1][j]>way[i][j-1])
        {
            i--;
        }
        else j--;
    }
}
int main()
{
    while(cin>>a>>b)
    {
        memset(way,0,sizeof(way));
        cout<<lcs(a.size(),b.size())<<endl;
        path_print(lcs(a.size(),b.size()), a.size(), b.size());
        cout<<s<<endl;
    }
    return 0;
}
