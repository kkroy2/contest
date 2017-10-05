#include <bits/stdc++.h>
#define INF 1000000000000LL
using namespace std;

long long dp[55][1005];
long long tme[1005][1005];
long long cst[1005][1005];

int n, t;

long long f(int u, int rem){
    if(rem<0) return INF;
    if(u==(n-1)) return 0LL;
    if(dp[u][rem]!=-1LL) return dp[u][rem];
    dp[u][rem]=INF;
    for(int i=0; i<n; i++){
        if(u!=i)dp[u][rem]=min(dp[u][rem], cst[u][i]+f(i, rem-tme[u][i]));
    }
    return dp[u][rem];
}

long long path_print(int u, int rem){
    if(u==(n-1)) return t-rem;
    long long min_cost=INF;
    int nxt=u;
    for(int i=0; i<n; i++){
        if(u!=i){
            if((cst[u][i]+dp[i][rem-tme[u][i]])<min_cost){
                min_cost=cst[u][i] + dp[i][rem-tme[u][i]];
                nxt=i;
            }
        }
    }
    return path_print(nxt, rem-tme[u][nxt]);
}

int main(){
    freopen("in.txt","r",stdin);
    while(1){
        scanf("%d %d", &n, &t);
        if(n==0 && t==0) break;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%lld", &tme[i][j]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%lld", &cst[i][j]);
            }
        }
        long long ans=f(0, t);
        printf("%lld %lld\n", ans, path_print(0, t));
    }
    return 0;
}
