#include<cstdio>

#include<cstring>

using namespace std;

const int mo=1e9+7,MAXN=42,MAXS=1<<17|1;

int n,x,y,z;

int f[MAXN][MAXS],g[MAXS][11];

inline void add(int &x,const int &y)

{

	x+=y;

	x>=mo? x-=mo:0;

}

int main()

{

	scanf("%d%d%d%d",&n,&x,&y,&z);

	y+=x,z+=y;

	int s=1<<z;

	for(int i=1;i<=s;i++)

		for(int j=1;j<=10;j++)

		{

			g[i][j]=1;

			if(i==s)

				g[i][j]=s;

			else

			{

				for(int k=0;k<z;k++)

					if((i>>k&1)&&k+j<=z&&!(k<x&&k+j>x)&&!(k<y&&k+j>y))

						g[i][j]|=1<<k+j;

				if(g[i][j]>=s)

					g[i][j]=s;

			}

		}

	f[0][1]=1;

	for(int i=0;i<n;i++)

		for(int j=1;j<=s;j++)

			if(f[i][j])

				for(int k=1;k<=10;k++)

					add(f[i+1][g[j][k]],f[i][j]);

	printf("%d",f[n][s]);

	return 0;

}