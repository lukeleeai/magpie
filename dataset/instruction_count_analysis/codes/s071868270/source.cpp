#include<iostream>

#include<cstdio>

#include<cstring>

#include<string>

#include<cmath>

#include<algorithm>

#include<map>

#include<queue>

#include<deque>

#include<stack>

#define INF 0X3F3F3F3F

#define LL long long

#define SC(x) scanf("%d",&x)

#define SCC(x,y) scanf("%d%d",&x,&y)

#define SCCC(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define FF(i,a,b) for(int i=a; i<=b; i++)

#define RR(i,a,b) for(int i=a; i>=b; i--)

#define FC(i,a,b) for(int i=a; i<b; i++)

#define SS(x) scanf("%s",x)

#define PR(x) printf("%d\n",x)

#define PRR(x,y) printf("%d%d\n",x,y)

#define CL(a,x) memset(a,x,sizeof(a))

#define MID int mid=((l+r)>>1)

#define lson x<<1,l,mid

#define rson x<<1|1,mid+1,r

#define _X sum[x]

#define _L sum[x<<1]

#define _R sum[x<<1|1]

#define IN freopen("in.txt","r",stdin)

#define OUT freopen("out.txt","w",stdout)

#define MAIN 10000010

#define MAXN 50010

using namespace std;

int n,m,a[MAXN];

map <int,int> mm;

int main()

{

    mm.clear();

    SC(n);

    FF(i,1,n)

    {

        SC(m);

        mm[m]++;

    }

    map <int,int>::iterator it;

    int f1=-1,f2=-1;

    for(it=mm.end();it!=mm.begin(); it--)

    {

        if(it->second>1)

        {

            if(f1==-1) f1=it->first,it->second-=2;

        }

        if(it->second>1)

        {

            if(f2==-1) f2=it->first,it->second-=2;

        }

        if(f1!=-1&&f2!=-1) break;

    }

    it=mm.begin();

    if(it->second>1)

    {

        if(f1==-1) f1=it->first,it->second-=2;

    }

    if(it->second>1)

    {

        if(f2==-1) f2=it->first,it->second-=2;

    }

    if(f1==-1||f2==-1) printf("0\n");

    else

    {

        LL ans=(LL)f1*(LL)f2;

        printf("%lld\n",ans);

    }

    return 0;

}
