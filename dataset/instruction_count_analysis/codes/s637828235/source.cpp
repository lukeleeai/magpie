#include "stdc++.h"

#define inf 1000000007

using namespace std;



int n,m,maxv=-1;

char a[25][25];

int GA[25][25][25][25];



int main()

{

	cin>>n>>m;

	memset(a,' ',sizeof(a));

	memset(GA,inf,sizeof(GA));

	for (int i=1;i<=n;i++)

	{

		for (int j=1;j<=m;j++)  cin>>a[i][j];

	}

	for (int i=1;i<=n;i++)

	{

		for (int j=1;j<=m;j++)

		{

			if (a[i][j]==a[i][j-1]&&a[i][j]=='.')  GA[i][j][i][j-1]=GA[i][j-1][i][j]=1;

			if (a[i][j]==a[i][j+1]&&a[i][j]=='.')  GA[i][j][i][j+1]=GA[i][j+1][i][j]=1;

			if (a[i][j]==a[i+1][j]&&a[i][j]=='.')  GA[i][j][i+1][j]=GA[i+1][j][i][j]=1;

			if (a[i][j]==a[i-1][j]&&a[i][j]=='.')  GA[i][j][i-1][j]=GA[i-1][j][i][j]=1;

		}

	}

	for (int i=1;i<=n;i++)

	{

		for (int j=1;j<=m;j++)  GA[i][j][i][j]=0;

	}

	for (int ki=1;ki<=n;ki++)

	{

		for (int kj=1;kj<=m;kj++)

		{

			if (a[ki][kj]=='#')  continue;

			for (int ii=1;ii<=n;ii++)

			{

				for (int ij=1;ij<=m;ij++)

				{

					if (a[ii][ij]=='#')  continue;

					for (int ji=1;ji<=n;ji++)

					{

						for (int jj=1;jj<=m;jj++)

						{

							if (a[ji][jj]=='#')  continue;

							if (GA[ii][ij][ji][jj]>GA[ii][ij][ki][kj]+GA[ki][kj][ji][jj])

							{

								GA[ii][ij][ji][jj]=GA[ii][ij][ki][kj]+GA[ki][kj][ji][jj];

								GA[ji][jj][ii][ij]=GA[ii][ij][ki][kj]+GA[ki][kj][ji][jj];

							}

						}

					}

				}

			}

		}

	}

	for (int ii=1;ii<=n;ii++)

	{

		for (int ij=1;ij<=m;ij++)

		{

			for (int ji=1;ji<=n;ji++)

			{

				for (int jj=1;jj<=m;jj++)

				{

					if (GA[ii][ij][ji][jj]>n*m)  continue;

					else maxv=max(maxv,GA[ii][ij][ji][jj]);

				}

			}

		}

	}

	cout<<maxv<<endl;

	return 0;

}
