#include<stdio.h>

int main()
{
    int n,i,j,k,space;
    scanf("%d",&n);
    space = n-1;
    for(i=1;i<=n;i++)
    {
        for(j=1; j<=space; j++)
        {
            printf(" ");
        }

        for(k=space+1;k<=n;k++) printf("%d",k);
        for(k=n-1;k>=space+1;k--) printf("%d",k);
        space--;
        puts("");

    }
    space = 1;
    for(i=1;i<=n-1;i++)
    {
        for(j=1; j<=space; j++)
        {
            printf(" ");
        }

        for(k=space+1;k<=n;k++) printf("%d",k);
        for(k=n-1;k>=space+1;k--) printf("%d",k);
        space++;
        puts("");

    }


    return 0;
}
