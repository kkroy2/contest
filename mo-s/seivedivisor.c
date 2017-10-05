#include<stdio.h>
#include<math.h>

int div[1010];

void kotogula_div(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j+=i) div[j]++;
    }

}
vector<int>divi[100000];
void all_divisor_list(int n)
{

    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j+=i) divi[j].push_back(i);
    }

}


int main()
{
    int n,i,t,c=1;
    d(1001);

    return 0;
}
