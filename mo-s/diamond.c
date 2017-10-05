#include<stdio.h>

int main()
{
    int n,i,j,space,k;
    scanf("%d",&n);
    space = n-1;

    for(i=1;i<=n;i++)
    {

        for(j=1;j<=space;j++) printf(" ");
        for(j=1;j<=n-space;j++){
            if(j==1)
            printf("*");
        else printf(" *");
        }
        space--;
        puts("");
    }
    space = 1;
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=space;j++) printf(" ");
        for(j=1;j<=n-space;j++){
            if(j==1)
            printf("*");
        else printf(" *");
        }
        space++;

        printf("\n");
    }
    return 0;
}

