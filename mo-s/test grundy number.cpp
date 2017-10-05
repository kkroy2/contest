#include<bits/stdc++.h>
using namespace std;

//Normal Nim-You have a SINGLE pile with n stones. you can remove 1 or 2 stones in each turn
/*
def can_win(s):
    if s==0: return 0
    if s==1: return 1
    if(can_win(s-1)==0 or can_win(s-2)==0):
        return 1
    return 0
    */

//Sprague Grundy number-You have n piles with s1,...,sn stones you can remove 1 or 2 stones

int vis[100];
int grundy_number(int cur)
{

    //cout<<cur<<" fsfs"<<endl;
    vis[cur] = 1;
    if(cur==0) return 0;
    else if(cur==1) return 1;
    int moves[] = {cur-1, cur-2};
    set<int>s;
    set<int>::iterator it;
    for(int i=0;i<2;i++)
    {
        if(vis[moves[i]]==0)
        s.insert(grundy_number(moves[i]));
    }
    int ans = 0;
    for(it=s.begin();it!=s.end();it++)
    {
        if(*it==ans) ans++;
        else break;
    }
   // while(s.find(ans)) ans++;
    return ans;
}
int main()
{

    cout<<grundy_number(4)<<endl;
    return 0;
}
