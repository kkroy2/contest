#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
#define pf(n) printf("%d\n",n)
#define pfcs(cs) printf("Case %d:\n",cs)
#define CASE(cs) printf("Case %d: ",cs)
#define enl cout<<endl
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define xx first
#define yy second

typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;


//bitmask//
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
////////////////////////////////////////////////////////

char st,c;

int k;

ll Hash(char s[], ll B, ll M)
{
    ll h = 0, power = 1;
    for(int i = strlen(s)-1; i>=0; i--)
    {
        h = h + (s[i] * power) % M;
        h = h % M;
        power = (power * B)%M;
    }
    return h;
}

ll bigmod(ll a, ll b, ll mod)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1LL)	ans = (ans * a) % mod;
        a = (a * a) % mod;
        b=b >> 1;
    }
    return ans;
}
ll forleft1(ll mod, ll B,int sl, int rl,ll hashstr, ll hashrev)
{
    ll temp = bigmod(B,sl,mod);
    temp = (temp * c) % mod;
    //cout<<((97*347)%mod *(347*347) % mod ) % mod<<" "<<temp<<endl;
    ll temp2 = bigmod(B,k,mod);
    //  cout<<temp2<<endl;
    temp2 = (temp2-1+mod+mod)%mod;
    //  cout<<temp2<<endl;
    temp = (temp * temp2) % mod;
    //  cout<<temp<<endl;
    ll temp3 = bigmod(B-1, mod-2,mod);
    temp = (temp * temp3) % mod;
    //  cout<<temp3<<" "<<temp<<endl;
    hashstr = (hashstr + temp) % mod;
    // cout<<"ok"<<" "<<hashstr<<endl;
    return hashstr;
}

ll forleft2(ll mod, ll B,int sl, int rl,ll hashstr, ll hashrev)
{
    ll temp,temp2,temp3;
    temp = bigmod(B,k,mod);
    //cout<<temp<<endl;
    temp = (temp-1+mod+mod)%mod;

    temp2 = bigmod(B-1,mod-2,mod);
    temp = (c*temp) % mod;
    temp = (temp * temp2) % mod;
    temp3 = bigmod(B,k,mod);
    hashrev = (((hashrev * temp3) % mod) + temp)%mod;
    return hashrev;
}
ll forright1(ll mod,ll B, int sl, int rl,ll hashstr, ll hashrev)
{
    ll temp,temp2,temp3;
    temp = bigmod(B,k,mod);
    temp = (temp-1+mod+mod)%mod;
    temp2 = bigmod(B-1,mod-2,mod);
    temp = (c*temp) % mod;
    temp = (temp * temp2) % mod;
    temp3 = bigmod(B,k,mod);
    hashstr = (((hashstr * temp3) % mod) + temp)%mod;
    return hashstr;

}

ll forright2(ll mod,ll B, int sl, int rl,ll hashstr, ll hashrev)
{
    ll temp,temp2,temp3;

    temp = bigmod(B,rl,mod);
    // cout<<"first "<<temp<<endl;
    temp = (temp * c) % mod;
    //   cout<<"temp "<<temp<<endl;
    temp2 = bigmod(B,k,mod);
    //  cout<<temp2<<endl;
    temp2 = (temp2-1+mod+mod)%mod;
    //  cout<<temp2<<endl;
    temp = (temp * temp2) % mod;
    //  cout<<temp<<endl;
    temp3 = bigmod(B-1, mod-2,mod);
    temp = (temp * temp3) % mod;
    //    cout<<"gjgmjhk "<<temp3<<" "<<temp<<endl;
    hashrev = (hashrev + temp) % mod;
    return hashrev;
}
ll cum1[2*1000006], cum2[2*1000006];
ll arr1[2*1000006], arr2[2*1000006];
int main()
{
    int t,cs=1;
    isc(t);
    ll B = 347, mod = 1000000000+7;
    ll B2 = 357, mod2 = 1000000000+9;
    int power = 1;
    arr1[0]=1;
    arr2[0]=1;
    for(int i=1;i<2*1000000;i++)
    {
        arr1[i] = (arr1[i-1] * 347) % mod;
        arr2[i] = (arr2[i-1] * 357) % mod;
        cum1[i] = cum1[i-1] + arr1[i];
        cum2[i] = cum2[i-1] + arr2[i];
    }
    while(t--)
    {
        char rev[100005],s[100005];
        scanf("%s",rev);
        strcpy(s,rev);
        int u;
        isc(u);


        reverse(rev,rev+strlen(rev));
        ll hashstr = Hash(s,B,mod);
        ll hashrev = Hash(rev,B,mod);
        ll hashstr2 = Hash(s,B2,mod2);
        ll hashrev2 = Hash(rev,B2,mod2);
        int sl = strlen(s), rl = strlen(rev);
        pfcs(cs++);

        for(int i=0; i<u; i++)
        {

            char ch = getchar();
            scanf("%c %c %d",&st,&c,&k);

            if(st=='L')
            {
                hashstr = forleft1(mod,B,sl,rl,hashstr,hashrev);
                hashrev = forleft2(mod,B,sl,rl,hashstr,hashrev);
                //hashstr2= forleft1(mod2,B2,sl,rl,hashstr2,hashrev2);
                //hashrev2 = forleft2(mod2,B2,sl,rl,hashstr2,hashrev2);
            }
            else if(st=='R')
            {
                hashstr = forright1(mod,B,sl,rl,hashstr,hashrev);
                hashrev = forright2(mod,B,sl,rl,hashstr,hashrev);
                //hashstr2= forright1(mod2,B2,sl,rl,hashstr2,hashrev2);
                //hashrev2 = forright2(mod2,B2,sl,rl,hashstr2,hashrev2);
            }
         //cout<<hashstr<<" "<<hashrev<<" "<<hashstr2<<" "<<hashrev2<<endl;
//      assert(hashstr>0);
//      assert(hashstr2>0);
//      assert(hashrev>0);
//      assert(hashrev2>0);
            //if(hashstr==hashrev && hashstr2==hashrev2) printf("Yes\n");
            if(hashstr==hashrev) printf("Yes\n");
            else printf("No\n");

            // cout<<hashstr<<" "<<hashrev<<endl;
            sl += k;
            rl += k;
        }

    }


    return 0;
}

