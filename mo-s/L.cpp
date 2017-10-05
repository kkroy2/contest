#include<bits/stdc++.h>
using namespace std;

bool manhatton_dis(int x, int y, int r, int c)
{
    int d = (r-x) + (c-y);
    if(d % 2==1) return true;
    else return false;
}
//int a[50005][50000];
int main()
{
    int t,n,r,c,v,x=0,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        x = 0;
        scanf("%d %d",&r, &c);
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                scanf("%d",&v);
                if(manhatton_dis(i,j,r,c))
                {
                 //   cout<<i<<" "<<j<<endl;
                    x^=v;
                }

            }
        }
        if(x) printf("Case %d: win\n",cs++);
        else printf("Case %d: lose\n",cs++);
    }

    return 0;
}

