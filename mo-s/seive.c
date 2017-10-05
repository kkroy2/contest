long long int prime[100000], nprime;
int mark[10000];
void seive(long long int n)
{
    long long int i,j,limit = sqrt(n*1.)+2;
    mark[1] = 1;
    for(i=4;i<=n;i+=2) mark[i] = 1;
    prime[nprime++] = 2;
    for(i=3;i<=n;i+=2){
        if(!mark[i])

            prime[nprime++] = i;
            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=i*2)
                {
                    mark[j] = i;
                }
            }

    }
}
