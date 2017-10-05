#include<bits/stdc++.h>
using namespace std;
/*
0 0
1 1

0 1 0
1 1 1
1 1 1

0 1 1 0
1 1 1 1
1 1 1 1
1 1 1 1
*/
int main()
{
    int n;
    cin>>n;
    if(n%2==0)
    {
        cout<<"white"<<endl;
        cout<<1<<" "<<2<<endl;
    }
    else cout<<"black"<<endl;
    return 0;
}
