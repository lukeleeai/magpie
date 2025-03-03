#include<stdio.h>

int main(void)

{

	int i,j,k,n,m,l,s,ss,kk,ll;

	char a[100][100];

	char b[100][100];

	scanf("%d%d",&n,&m);

	getchar();

	for(i=1;i<=n;i++)

	{

		for(j=1;j<=n;j++)

		{

			scanf("%c",&a[i][j]);

		}

		getchar();

	}

	for(i=1;i<=m;i++)

	{

		for(j=1;j<=m;j++)

		{

			scanf("%c",&b[i][j]);

		}

		getchar();

	}

	ss=0;

	for(i=1;i<=n-m+1;i++)

	{

		for(j=1;j<=n-m+1;j++)

		{

			if(a[i][j]==b[1][1])

			{

				s=0;

				for(k=i,kk=1;k<i+m;k++,kk++)

				{

					for(l=j,ll=1;l<j+m;l++,ll++)

					{

						if(a[k][l]!=b[kk][ll])

						{

							s=1;

							break;

						}

					}

					if(s==1)

					break;

				}

				if(s==0)

				{

					ss=1;

					break;

				}

			}

		}

		if(ss==1)

		break;

	}

	if(ss==1)

	printf("Yes\n");

	else

	printf("No\n");

	return 0;

}