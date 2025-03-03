#include"stdc++.h"

using namespace std;



const int mod=1000000007;

int f[61][61][61],n,c[61][61];



int main()

{

	for (int i=0; i<=60; i++)

	{

		c[i][0]=1;

		for (int j=1; j<=i; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;

	}

	scanf("%d",&n);

	for (int i=1; i<=n; i++) f[1][i/2][(i-1)/2]=n;

	for (int i=1; i<=n; i++)

		for (int j=0; j<=n; j++)

			for (int k=(j==0); k<=n; k++)

				if (f[i][j][k])

					for (int l=0; i+j+k+l<=n; l++)

						for (int m=0; i+j+k+l+m<=n; m++)

							if (max(0,l-m)<=min(k,l-m+j))

								f[i+j+k][l][m]=(f[i+j+k][l][m]+1ll*f[i][j][k]*c[j+k][m-l+k]%mod*c[n-i][j+k])%mod;

	printf("%d\n",f[n][0][0]);

	return 0;

}