//n log n solution, can be done in logn
#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long ull;
ull bigmod(ull a,ull b,ull M){  //(a^b)%M for integer M must be (M<10^5)
    if(b==0) return 1%M;        //O(log(n)) base of the log is 2
    ull re = bigmod(a,b/2,M);
    re = (re*re)%M;
    if(b&1) return(re*a)%M;
    return re;
}
ull bigsum(ull a,ull b, ull M){ //b<21699
    if(b==0) return 0;
    ull sum = bigsum(a,b-1,M) + bigmod(a,b-1,M);/*a^b*/
    return sum%M;
}
int main()
{
    cout<<bigsum(999999999,21699,99999876)<<endl;
    return 0;
}

