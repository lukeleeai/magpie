#pragma GCC optimize(3,"Ofast","inline")

#include"stdc++.h"

using namespace std;

const int N=1e6+10;

int bl,t,n,m;

int res,a[N],cnt[N],ans[N];

int curR,curL;

struct node

{

  int l,r,p;

  bool operator <(const node &W)const

  {

    return l<W.l;

  }

}e[N];

bool cmp(const node &a,const node &b)

{

  return (a.l/bl)==(b.l/bl) ?  a.r<b.r : a.l>b.l;

}

void remove(int i)

{

  if((--cnt[a[i]])==0) res--;

}

void add(int i)

{

  if((++cnt[a[i]])==1) res++;

}

int main()

{



     memset(ans,0,sizeof(ans));

     memset(cnt,0,sizeof(cnt));

     scanf("%d %d",&n,&m);

     for(int i=1;i<=n;i++) scanf("%d",&a[i]);



     bl=sqrt(n);

     for(int i=1;i<=m;i++)

     {

       scanf("%d %d",&e[i].l,&e[i].r);

       e[i].p=i;

     }

     sort(e+1,e+1+m,cmp);

     res=0;

     curL=1;curR=0;

     for(int i=1;i<=m;i++)

     {

       int L=e[i].l,R=e[i].r;

       while(curL<L) remove(curL++);

       while(curL>L) add(--curL);

       while(curR<R) add(++curR);

       while(curR>R) remove(curR--);

       ans[e[i].p]=res;

     }

     for(int i=1;i<=m;i++) printf("%d\n",ans[i]);



}


