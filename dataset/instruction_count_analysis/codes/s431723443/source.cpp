#include <cstdio>



const int maxn=200000;



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



int n,a[maxn+10];

long long ans;



int main()

{

  n=read();

  for(int i=1; i<=n; ++i)

    {

      a[i]=read();

      if(a[i]>=i)

        {

          puts("-1");

          return 0;

        }

    }

  for(int i=2; i<=n; ++i)

    {

      if(a[i]>a[i-1]+1)

        {

          puts("-1");

          return 0;

        }

      if(a[i]==a[i-1]+1)

        {

          ++ans;

        }

      else

        {

          ans+=a[i];

        }

    }

  printf("%lld\n",ans);

  return 0;

}