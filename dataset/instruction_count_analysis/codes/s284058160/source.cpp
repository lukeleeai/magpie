#include <cstdio>



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



const int maxn=200;

const int mod=998244353;



struct point

{

  int x,y;

};



point p[maxn+10];

int n,ans;



int quickpow(int a,int b,int m)

{

  int res=1;

  while(b)

    {

      if(b&1)

        {

          res=1ll*res*a%m;

        }

      a=1ll*a*a%m;

      b>>=1;

    }

  return res;

}



int in_line(point a,point b,point c)

{

  return (b.y-a.y)*(c.x-a.x)==(c.y-a.y)*(b.x-a.x);

}



int main()

{

  n=read();

  for(int i=1; i<=n; ++i)

    {

      p[i].x=read();

      p[i].y=read();

    }

  for(int i=1; i<=n; ++i)

    {

      for(int j=i+1; j<=n; ++j)

        {

          int cnt=0;

          for(int k=j+1; k<=n; ++k)

            {

              if(in_line(p[i],p[j],p[k]))

                {

                  ++cnt;

                }

            }

          ans+=quickpow(2,cnt,mod);

          if(ans>=mod)

            {

              ans-=mod;

            }

        }

    }

  ans+=n+1;

  if(ans>=mod)

    {

      ans-=mod;

    }

  ans=quickpow(2,n,mod)-ans;

  if(ans<0)

    {

      ans+=mod;

    }

  printf("%d\n",ans);

  return 0;

}
