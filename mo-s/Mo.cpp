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
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
////////////////////////////////////////////////////////
const int N = 200005;
const int A = 1000005;
ll cnt[A];
int a[N];
long long ans[N], answer = 0;
int BLOCK = 1500;
struct node {
	int L, R, i;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int position) {
    answer -= (cnt[a[position]]*cnt[a[position]]*a[position]);
	cnt[a[position]]++;
	answer += (cnt[a[position]]*cnt[a[position]]*a[position]);
}

void remove(int position) {

	answer -= (cnt[a[position]]*cnt[a[position]]*a[position]);
	cnt[a[position]]--;
	answer += (cnt[a[position]]*cnt[a[position]]*a[position]);
}

int main()
{
    int n,t,l,r;

    isc(n); isc(t);
    rept(i,0,n) isc(a[i]);
    rept(i,0,t)
    {
        isc(q[i].L); isc(q[i].R);
        q[i].L--; q[i].R--;
        q[i].i = i;
    }
    //BLOCK = sqrt(n);
    sort(q,q+t,cmp);

    int currentL = 0, currentR = 0;
	for(int i=0; i<t; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
		ans[q[i].i] = answer;
	}

	for(int i=0; i<t; i++)
		printf("%I64d\n",ans[i]);
    return 0;
}

