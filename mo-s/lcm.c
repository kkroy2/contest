#include<stdio.h>
#include<math.h>

int main()
{
    long long int x,y,lcm;
    scanf("%lld %lld",&x,&y);
    long long int a = x, b = y;
    while(x!=0)
    {
        long long int temp = x;
        x = y%x;
        y = temp;
    }
    lcm = a * (b/y);
    printf("%lld\n",lcm);
    return 0;
}
