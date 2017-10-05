#include<bits/stdc++.h>
using namespace std;

int way[2020][2020];
/*int disit(char a[], char b[])
{

    for(int i=0; i<=strlen(a); i++)
    {
        for(int j=0; j<=strlen(b); j++)
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

    return way[strlen(a)][strlen(b)];
}


bool samecase(int i, int j)
{
    if(a[i]==a)
}
int dis(int i, int j)
{
    if()
    {
        1 + min(dis(i-1,j-1), min(dis(i-1,j), dis(i,j-1)));
    }

}*/
int main()
{
    int t,i;
    char a[1010];
    while(cin>>a)
    {
        int b[1007], c[1007];
        for(i=0; i<strlen(a); i++)
        {
            if(i%2==0 && isupper(a[i]))
                b[i] = a[i] - 'A' + 'a';
            else if(i%2==0 && islower(a[i]))
                b[i] = a[i];

            else if(i%2==1 && isupper(a[i]))
                b[i] = a[i];

            else b[i] = a[i] - 'a' + 'A' ;
            //cout<<b[i];
        }
       b[i] = '\0';
        // cout<<endl;
        // b[i] = '\0';
        for(i=0; i<strlen(a); i++)
        {
            if(i%2==1 && isupper(a[i]))
                c[i] = a[i] - 'A' + 'a';
            else if(i%2==1 && islower(a[i]))
                c[i] = a[i];

            else if(i%2==0 && isupper(a[i]))
                c[i] = a[i];

            else c[i] = a[i] - 'a' + 'A' ;
            // cout<<c[i];
        }
        c[i] = '\0';
        //cout<<endl;
        int x=0,y=0;
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]!=b[i]) x++;
            if(a[i]!=c[i]) y++;
        }
       /* memset(way,0,sizeof(way));
        int x = disit(a,b);
        memset(way,0,sizeof(way));
        int y = disit(a,c);
       cout<<x<<" "<<y<<endl;*/
        int mini = min(x,y);
        cout<<mini<<endl;
        //cout<<a<<endl;
        //cout<<b<<endl;
        //cout<<c<<endl;


    }
    return 0;
}
