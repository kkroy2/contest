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
int arr[20],data[20];
//combination(0, n-1, 0, r);
void combination(int start, int ende,int index, int r,int &num)
{
    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%d ", data[j]);
        printf("\n");
        num++;
        return;
    }

    for (int i=start; i<=ende && ende-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combination(i+1, ende, index+1, r,num);
    }
}
void swape(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swape((a+l), (a+i));
          permute(a, l+1, r);
          swape((a+l), (a+i));
       }
   }
}
void printArr(int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    printf("\n");
}
void heapPermutation(int sz, int n)
{
    if (sz == 1)
    {
        printArr(n);
        return;
    }
    for (int i=0; i<sz; i++)
    {
        heapPermutation(sz-1,n);
        if (sz%2==1)
            swap(arr[0], arr[sz-1]);
        else
            swap(arr[i], arr[sz-1]);
    }
}
int compare (const void *a, const void * b)
{  return ( *(char *)a - *(char *)b ); }
void swap (char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
int findCeil (char str[], char first, int l, int h)
{
    int ceilIndex = l;
    for (int i = l+1; i <= h; i++)
      if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
    return ceilIndex;
}
void sortedPermutations ( char str[] )
{
    int sz = strlen(str);
    qsort( str, sz, sizeof( str[0] ), compare );
    bool isFinished = false;
    while ( ! isFinished )
    {
        printf ("%s \n", str);
        int i;
        for ( i = sz - 2; i >= 0; --i )
           if (str[i] < str[i+1])
              break;
        if ( i == -1 )
            isFinished = true;
        else
        {
            int ceilIndex = findCeil( str, str[i], i + 1, sz - 1 );
            swap( &str[i], &str[ceilIndex] );
            qsort( str + i + 1, sz - i - 1, sizeof(str[0]), compare );
        }
    }
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cout.flush();
    //freopen("out.txt","w",stdout);
    rept(i,0,10)arr[i]=i;
    int num=0;
    combination(0, 9, 0, 4,num);
    cout<<num;
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
    heapPermutation(3, 2);
    sortedPermutations( str );
    return 0;
}

