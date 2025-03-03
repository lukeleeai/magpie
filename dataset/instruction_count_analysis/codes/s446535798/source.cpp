#include <cstdio>

#include <algorithm>



int read()

{

  int x=0,f=1;

  char ch=getchar();

  while((ch<'0')||(ch>'9'))

    {

      if(ch=='-')

        {

          f=-f;

        }

      ch=getchar();

    }

  while((ch>='0')&&(ch<='9'))

    {

      x=x*10+ch-'0';

      ch=getchar();

    }

  return x*f;

}



const int maxn=200000;

const long long inf=0x3f3f3f3f3f3f3f3fll;



int n,q,sta,stb,a[maxn+10];



namespace sgt

{

  long long mn[3][maxn<<2],adt[maxn<<2];



  int puttag(int x,long long v)

  {

    mn[0][x]+=v;

    mn[1][x]+=v;

    mn[2][x]+=v;

    adt[x]+=v;

    return 0;

  }



  int pushdown(int x)

  {

    puttag(x<<1,adt[x]);

    puttag(x<<1|1,adt[x]);

    adt[x]=0;

    return 0;

  }



  int updata(int x)

  {

    mn[0][x]=std::min(mn[0][x<<1],mn[0][x<<1|1]);

    mn[1][x]=std::min(mn[1][x<<1],mn[1][x<<1|1]);

    mn[2][x]=std::min(mn[2][x<<1],mn[2][x<<1|1]);

    return 0;

  }



  int build(int x,int l,int r)

  {

    if(l==r)

      {

        mn[0][x]=inf+l;

        mn[1][x]=inf+n-l+1;

        mn[2][x]=inf;

        return 0;

      }

    int mid=(l+r)>>1;

    build(x<<1,l,mid);

    build(x<<1|1,mid+1,r);

    updata(x);

    return 0;

  }



  int add(int x,int l,int r,int askl,int askr,long long adv)

  {

    if((askl<=l)&&(r<=askr))

      {

        puttag(x,adv);

        return 0;

      }

    int mid=(l+r)>>1;

    pushdown(x);

    if(askl<=mid)

      {

        add(x<<1,l,mid,askl,askr,adv);

      }

    if(mid<askr)

      {

        add(x<<1|1,mid+1,r,askl,askr,adv);

      }

    updata(x);

    return 0;

  }



  long long getmn(int x,int l,int r,int askl,int askr,int id)

  {

    if((askl<=l)&&(r<=askr))

      {

        return mn[id][x];

      }

    int mid=(l+r)>>1;

    long long res=inf<<1;

    pushdown(x);

    if(askl<=mid)

      {

        res=std::min(res,getmn(x<<1,l,mid,askl,askr,id));

      }

    if(mid<askr)

      {

        res=std::min(res,getmn(x<<1|1,mid+1,r,askl,askr,id));

      }

    return res;

  }

}



int abs(int x)

{

  return (x<0)?(-x):x;

}



int main()

{

  n=read();

  q=read();

  sta=read();

  stb=read();

  for(int i=1; i<=q; ++i)

    {

      a[i]=read();

    }

  a[0]=sta;

  sgt::build(1,1,n);

  sgt::add(1,1,n,stb,stb,-inf);

  for(int i=1; i<=q; ++i)

    {

      long long oth=std::min(sgt::getmn(1,1,n,1,a[i],1)-(n-a[i]+1),sgt::getmn(1,1,n,a[i],n,0)-a[i]);

      sgt::add(1,1,n,1,n,abs(a[i]-a[i-1]));

      long long nth=sgt::getmn(1,1,n,a[i-1],a[i-1],2);

      if(nth>oth)

        {

          sgt::add(1,1,n,a[i-1],a[i-1],oth-nth);

        }

    }

  printf("%lld\n",sgt::getmn(1,1,n,1,n,2));

  return 0;

}
