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



const int maxn=3000;

const int mod=1000000007;



int n,k,f[maxn+10][maxn+10][2],ans;



int main()

{

  n=read();

  k=read();

  for(int i=0; i<=n; ++i)

    {

      f[0][i][(i==0)]=1;

    }

  for(int i=0; i<k; ++i)

    {

      for(int j=0; j<=n; ++j)

        {

          for(int sta=0; sta<2; ++sta)

            {

              if(j>0)

                {

                  f[i+1][j-1][sta|(j==1)]+=f[i][j][sta];

                  if(f[i+1][j-1][sta|(j==1)]>=mod)

                    {

                      f[i+1][j-1][sta|(j==1)]-=mod;

                    }

                  f[i+1][j][sta|(j==1)]+=f[i][j][sta];

                  if(f[i+1][j][sta|(j==1)]>=mod)

                    {

                      f[i+1][j][sta|(j==1)]-=mod;

                    }

                }

              if(j<n)

                {

                  f[i+1][j+1][sta]+=f[i][j][sta];

                  if(f[i+1][j+1][sta]>=mod)

                    {

                      f[i+1][j+1][sta]-=mod;

                    }

                  f[i+1][j][sta]+=f[i][j][sta];

                  if(f[i+1][j][sta]>=mod)

                    {

                      f[i+1][j][sta]-=mod;

                    }

                }

            }

        }

    }

  for(int i=0; i<=n; ++i)

    {

      ans+=f[k][i][1];

      if(ans>=mod)

        {

          ans-=mod;

        }

    }

  printf("%d\n",ans);

  return 0;

}
