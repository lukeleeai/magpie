#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#define N 505

using namespace std;

int n,m,l,r,ans,mid;

int a[N][N],b2[N],MAX;

int read()

{int t=0;char c;

  c=getchar();

  while(!(c>='0' && c<='9')) c=getchar();

  while(c>='0' && c<='9')

	{

	  t=t*10+c-48;c=getchar();

    }

   return t;

}

bool b1[N];

int main()

{int i,j,k;

   n=read();m=read();

   for(i=1;i<=n;i++)

	   for(j=1;j<=m;j++) a[i][j]=read();

    ans=n;memset(b1,false,sizeof(b1));

    for(i=1;i<=m;i++)

	{

        for(j=1;j<=m;j++) b2[j]=0;

        for(j=1;j<=n;j++)

        for(k=1;k<=m;k++)

        if(!b1[a[j][k]])

		{

         b2[a[j][k]]++;break;

        }

		k=1;

        for(j=2;j<=m;j++) if(b2[j]>b2[k])k=j;

        b1[k]=true;

		ans=min(ans,b2[k]);

    }

	printf("%d\n",ans);

}