#include<stdio.h>
//Phi for all numbers from 1 to n
int phi[1000005];
int mark2[1000006];

void seivephi(int n)
{
    int i,j;
    for(i=1;i<=n;i++) phi[i] = i;
    phi[1] = 1;
    mark2[1] = 1;
    for(i=2;i<=n;i++)
    {
        if(mark2[i]==0)
        {
            for(j=i;j<=n;j+=i){
                mark2[j] =1;
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }
   // printf("%d",phi[n]);
}

int main()
{
    seivephi(1000000);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",phi[n]);
    }
    //seive(2);
    return 0;
}
