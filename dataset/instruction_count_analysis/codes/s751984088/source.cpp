#include<cstdio>

using namespace std;

char s[100001];

char t[100001];

int a[100000];

int main()

{

	int n,i,j,k;

	scanf("%d",&n);

	scanf("%s",s);

	for(i=0;i<2;i++)

	{

		for(j=0;j<2;j++)

		{

			if(i==0)

			{

				a[0]=0;

			}

			else

			{

				a[0]=1;

			}

			if(j==0)

			{

				a[1]=0;

			}

			else

			{

				a[1]=1;

			}

			for(k=2;k<n;k++)

			{

				if(s[k-1]=='o')

				{

					if(a[k-1]==0)

					{

						a[k]=a[k-2];

					}

					else

					{

						a[k]=1-a[k-2];

					}

				}

				else

				{

					if(a[k-1]==0)

					{

						a[k]=1-a[k-2];

					}

					else

					{

						a[k]=a[k-2];

					}

				}

			}

			if(s[n-1]=='o')

			{

				if(a[n-1]==0)

				{

					if(a[n-2]!=a[0])

						continue;

				}

				else

				{

					if(a[n-2]==a[0])

						continue;

				}

			}

			else

			{

				if(a[n-1]==0)

				{

					if(a[n-2]==a[0])

						continue;

				}

				else

				{

					if(a[n-2]!=a[0])

						continue;

				}

			}

			if(s[0]=='o')

			{

				if(a[0]==0)

				{

					if(a[n-1]!=a[1])

						continue;

				}

				else

				{

					if(a[n-1]==a[1])

						continue;

				}

			}

			else

			{

				if(a[0]==0)

				{

					if(a[n-1]==a[1])

						continue;

				}

				else

				{

					if(a[n-1]!=a[1])

						continue;

				}

			}

			for(k=0;k<n;k++)

			{

				if(a[k]==0)

				{

					t[k]='S';

				}

				else

				{

					t[k]='W';

				}

			}

			printf("%s\n",t);

			return 0;

		}

	}

	puts("-1");

	return 0;

}