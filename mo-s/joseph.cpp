int jossephus(int n, int k)
{
    if(n==1) return 0;
    return (jossephus(n-1,k)+k)%n;
}
