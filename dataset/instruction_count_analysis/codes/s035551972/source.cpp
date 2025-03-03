#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

#include <limits.h>

#include <assert.h>

#include <math.h>

#include <iostream>

#include <algorithm>

#include <map>

#include <set>

#include <stack>

#include <queue>

#include <string>

#include <bitset>

#include <vector>

using namespace std;



#define LL long long



#define fi first

#define se second

#define lson l,mid,id<<1

#define rson mid+1,r,id<<1|1

#define ls id<<1

#define rs id<<1|1

#define MID(a,b) (((a)+(b))>>1)

#define maxx(a,b) ((a)<(b)?(b):(a))

#define minx(a,b) ((a)<(b)?(a):(b))

#define absx(a) ((a)<0?-(a):(a))

#define mk(a,b) make_pair(a,b)

#define pb(a) push_back(a)

#define itr iterator

#define lowbit(x) ((x)&-(x))



typedef unsigned LL ULL;

typedef unsigned uint;

typedef map<int,int> mii;

typedef pair<int,int> pii;

typedef pair<double,double> pdd;

typedef pair<LL,LL> pLL;



template< typename T > inline void read(T &x) {

    bool f; char ch; f=0; x=0; ch=getchar();

    while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}

    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}

    if(f) x=-x;

}



template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}

template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}

template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}



const double pi=(double) acos(-1.0);

const int MOD=(int) 1e9+7;

const int INF=(int) 0x3f3f3f3f;

const LL  LINF=(LL) INF<<32|INF;

const int SINF=(uint) ~0>>1;

const LL  SLINF=(ULL) (-1)>>1;

const double DINF=(double) 1e50;

const double eps=(double) 1e-8;

const int maxn=(int) 2e5+20;

const int maxm=(int) 1e5+20;

const int maxk=(int) 5e2+20;



inline int sig(double x) {return x<-eps?-1:x>eps;}



//--------------start------------------



int n,m;

int a[maxn],sum[maxn];

int T[maxn<<2];

int dp[maxn];



int i,j,pos,tmp,tmp2,l,r;



struct adjs{int to,next;}ad[maxn<<1];

int head[maxn],adcnt;

inline void adjs_init() {for(i=1;i<=n;i++) head[i]=-1; adcnt=0;}

inline void adde(int a,int b)

{

    ad[adcnt].next=head[a]; ad[adcnt].to=b;

    head[a]=adcnt++;

}



#define ROOT 1,n,1

void build(int l,int r,int id)

{

    T[id]=INF;

    if(l==r) return ;

    int mid=MID(l,r);

    build(lson);

    build(rson);

}



void update(int val,int L,int R,int l,int r,int id)

{

    if(L<=l && r<=R)

    {

        Min(T[id],val);

        return ;

    }

    int mid=MID(l,r);

    if(L<=mid) update(val,L,R,lson);

    if(mid<R)  update(val,L,R,rson);

}



int query(int pos,int l,int r,int id)

{

    if(l==r) return T[id];

    int mid=MID(l,r);

    if(pos<=mid) return min(query(pos,lson),T[id]);

    else return min(query(pos,rson),T[id]);

}



void work()

{

    read(n);

    for(i=1;i<=n;i++) read(a[i]), sum[i]=sum[i-1]+!a[i];

    adjs_init();



    read(m);

    while(m--)

    {

        read(l), read(r);

        adde(r,l);

    }



    build(ROOT);

    dp[0]=0;



    for(i=1;i<=n;i++)

    {

        dp[i]=dp[i-1]+a[i];

        for(j=head[i];~j;j=ad[j].next)

        {

            pos=ad[j].to;

            tmp=dp[pos-1]+(sum[i]-sum[pos-1]);

            tmp2=query(pos,ROOT)+sum[i];

            Min(tmp,tmp2);

            update(tmp-sum[i],pos,i,ROOT);

            Min(dp[i],tmp);

        }

    }



    printf("%d\n",dp[n]);

}



//--------------end--------------------



int main()

{

#ifdef yukihana0416

freopen("in.txt","r",stdin);

//freopen("out.txt","w",stdout);

#endif // yukihana0416

    work();

    return 0;

}
