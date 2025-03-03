#include "stdc++.h"

#define maxn 800

#define maxm 1009

using namespace std;

int b[maxn][maxn],a[maxn][maxn];

int  guass(int n)

{

	int i,j,p,row=0,col=0;

	for(;row<n&&col<n;row++,col++)

	{

		for(i=row,p=row;i<n;i++)

			if(a[i][col])

			{p=i;break;}

		if(p!=row)

			for(j=col;j<=n;j++)

				swap(a[p][j],a[row][j]);

		if(!a[row][col]) 

		{

			row--;

			continue;

		}

		for(i=row+1;i<n;i++)

			if(a[i][col])

			for(j=col+1;j<=n;j++)

				a[i][j]^=a[row][j];

	}

	for(i=row;i<n;i++)

		if(a[i][n]) return 0;

	return 1;

}

int main()

{

	int n,m,d;

	while(scanf("%d%d%d",&m,&n,&d)!=EOF&&n+m+d)

	{

		for(int i=0;i<n;i++)

		{

			for(int j=0;j<m;j++)

				scanf("%d",&b[i][j]);

		}

		memset(a,0,sizeof(a));

		for(int i=0;i<n;i++)

		{

			for(int j=0;j<m;j++)

			{

				a[i*m+j][n*m]=b[i][j];

				a[i*m+j][i*m+j]=1;

				for(int x=0;x<n;x++)

				{

					for(int y=0;y<m;y++)

					{

						if(abs(x-i)+abs(y-j)==d)

							a[i*m+j][x*m+y]=1;

					}

				}

			}

		}

		if(guass(n*m))

			puts("1");

		else

			puts("0");

	}

	return 0;

}