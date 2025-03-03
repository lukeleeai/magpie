#include <cstdio>

#include <iostream>



using namespace std;



const int MAXN = 1010;

const int MOD = 1e9+7;



int n, m, a[MAXN][MAXN];

int f[MAXN][MAXN];

char s[MAXN];



int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

	{

		scanf("%s",s+1);

		for(int j=1;j<=m;j++)

		{

			a[i][j] = s[j] == '.';

		}

	}

	f[1][1] = 1;

	for(int i=1;i<=n;i++)

	{

		for(int j=1;j<=m;j++)

		{

			if(i==1 && j==1) continue;

			if(a[i][j]) f[i][j] = (f[i-1][j] + f[i][j-1])%MOD;

		}

	}

	printf("%d\n",f[n][m]);

	return 0;

}