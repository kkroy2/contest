#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;
typedef priority_queue<PI,vector<PI>,greater<PI>> Minheap;
//ios_base::sync_with_stdio(false);cin.tie(NULL);
const long long int N=1e5+7;
struct point{
    int a,b;
    point (){}
    point(int _a,int _b)
    {
        a=_a;
        b=_b;
    }
};
bool operator<(point a,point b)
{
    if(a.a==b.a)return a.b<b.b;
    return a.a<b.a;
}
//----------------------------------------------------------------------------------------------------------------------------------------//
int can_win(n)
{
	if n==0 or n==1: return 0
	if(can_win(n-2)==0 or can_win(n-3)==0 or can_win(n-5)==0):
		return 1
	return 0
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cout.flush();
    //freopen("out.txt","w",stdout);
    return 0;
}
struct move
{
    int pile_index;
    int stones_removed;
};

bool gameOver(int piles[], int n)
{
    int i;
    for (i=0; i<n; i++)
        if (piles[i]!=0)
            return (false);

    return (true);
}
int calculateNimSum(int piles[], int n)
{
    int i, nimsum = piles[0];
    for (i=1; i<n; i++)
        nimsum = nimsum ^ piles[i];
    return(nimsum);
}

void makeMove(int piles[], int n, struct move * moves)
{
    int i, nim_sum = calculateNimSum(piles, n);

    if (nim_sum != 0)
    {
        for (i=0; i<n; i++)
        {
            // If this is not an illegal move
            // then make this move.
            if ((piles[i] ^ nim_sum) < piles[i])
            {
                (*moves).pile_index = i;
                (*moves).stones_removed =
                                 piles[i]-(piles[i]^nim_sum);
                piles[i] = (piles[i] ^ nim_sum);
                break;
            }
        }
    }
    else
    {
        // Create an array to hold indices of non-empty piles
        int non_zero_indices[n], count;

        for (i=0, count=0; i<n; i++)
            if (piles[i] > 0)
                non_zero_indices [count++] = i;

        (*moves).pile_index = (rand() % (count));
        (*moves).stones_removed =
                 1 + (rand() % (piles[(*moves).pile_index]));
        piles[(*moves).pile_index] =
         piles[(*moves).pile_index] - (*moves).stones_removed;

        if (piles[(*moves).pile_index] < 0)
            piles[(*moves).pile_index]=0;
    }
    return;
}

void playGame(int piles[], int n, int whoseTurn)
{
    struct move moves;
    while (gameOver (piles, n) == false)
    {
        makeMove(piles, n, &moves);
        if (whoseTurn == 1)whoseTurn = 2;
        else whoseTurn = 1;
    }
    return;
}

int winner(int piles[], int n,int whoseTurn)
{

    if (calculateNimSum(piles, n) !=0)return 1
    else return 2/
}

int main()
{
    int piles[] = {3, 4, 5};
    int n = sizeof(piles)/sizeof(piles[0]);
    playGame(piles, n, 1);
    return(0);
}

int calculateMex(unordered_set<int> Set)
{
    int Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}
int calculateGrundy(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    if (n == 2)
        return (2);
    if (n == 3)
        return (3);

    unordered_set<int> Set;

    for (int i=1; i<=3; i++)
            Set.insert(calculateGrundy(n - i));

    return (calculateMex(Set));
}

int calculateGrundy(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    if (n == 2)
        return (2);
    if (n == 3)
        return (3);
    int p[n];
    memset(p,0,sizeof(p));
    for (int i=1; i<=3; i++)
            p[calculateGrundy(n - i)]++;
    for (int i=1; i<=N; i++)if(p[i]==0)return p[i];
}

#define PLAYER1 1
#define PLAYER2 2
int calculateMex(unordered_set<int> Set)
{
    int Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}
int calculateGrundy(int n, int Grundy[])
{
    Grundy[0] = 0;
    Grundy[1] = 1;
    Grundy[2] = 2;
    Grundy[3] = 3;

    if (Grundy[n] != -1)
        return (Grundy[n]);
    unordered_set<int> Set;
    for (int i=1; i<=3; i++)
            Set.insert (calculateGrundy (n-i, Grundy));
    Grundy[n] = calculateMex (Set);
    return (Grundy[n]);
}

void declareWinner(int whoseTurn, int piles[],
                    int Grundy[], int n)
{
    int xorValue = Grundy[piles[0]];

    for (int i=1; i<=n-1; i++)
        xorValue = xorValue ^ Grundy[piles[i]];

    if (xorValue != 0)
    {
        if (whoseTurn == PLAYER1)
            printf("Player 1 will win\n");
        else
            printf("Player 2 will win\n");
    }
    else
    {
        if (whoseTurn == PLAYER1)
            printf("Player 2 will win\n");
        else
            printf("Player 1 will win\n");
    }

    return;
}
int main()
{
    int piles[] = {3, 4, 5};
    int n = sizeof(piles)/sizeof(piles[0]);
    int maximum = *max_element(piles, piles + n);
    int Grundy[maximum + 1];
    memset(Grundy, -1, sizeof (Grundy));
    for (int i=0; i<=n-1; i++)
        calculateGrundy(piles[i], Grundy);
    declareWinner(PLAYER1, piles, Grundy, n);
    return (0);
}
