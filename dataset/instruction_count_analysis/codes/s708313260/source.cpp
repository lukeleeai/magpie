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



const int maxn=100000;



int n,pre[maxn*2+10],now[maxn+10],son[maxn*2+10],tot,f[maxn+10];



int ins(int a,int b)

{

  pre[++tot]=now[a];

  now[a]=tot;

  son[tot]=b;

  return 0;

}



int search(int u,int fa)

{

  for(int i=now[u]; i; i=pre[i])

    {

      int v=son[i];

      if(v==fa)

        {

          continue;

        }

      search(v,u);

      f[u]^=(f[v]+1);

    }

  return 0;

}



int main()

{

  n=read();

  for(int i=1; i<n; ++i)

    {

      int a=read(),b=read();

      ins(a,b);

      ins(b,a);

    }

  search(1,0);

  puts(f[1]?"Alice":"Bob");

  return 0;

}
