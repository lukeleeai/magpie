#include<cstring>

#include<cstdio>

#include<iostream>

using namespace std;

char s[100010];

int r[100010];

bool flag;

int main()

{

	int n;

	while(scanf("%d",&n)==1)

	{

		scanf("%s",s);

		int num=0;

		while(num<4)

		{

			flag=true;

			if(num==0)

			{

				r[0]=1;

			    r[1]=1;

			}

			if(num==1)

			{

				r[0]=1;

			    r[1]=0;

			}

			if(num==2)

			{

				r[0]=0;

			    r[1]=1;

			}

			if(num==3)

			{

				r[0]=0;

			    r[1]=0;

			}

			//printf("%d %d\n",r[0],r[1]);

			for(int i=0;i<n;i++)

			{

				if(i==0)

				{

					if(s[i]=='o')

					{

						if(r[i]==1)

						r[n-1]=r[i+1];

						if(r[i]==0)

						r[n-1]=1-r[i+1];

					}

					if(s[i]=='x')

					{

						if(r[i]==1)

						r[n-1]=1-r[i+1];

						if(r[i]==0)

						r[n-1]=r[i+1];

					}

				}

				

				if(i==n-1)

				{

					if(s[i]=='o')

					{

						if(r[i]==1)

						if(r[i-1]!=r[0])

						flag=false;

						if(r[i]==0)

						if(r[i-1]==r[0])

						flag=false;

					}

					if(s[i]=='x')

					{

						if(r[i]==1)

						if(r[i-1]==r[0])

						flag=false;

						if(r[i]==0)

						if(r[i-1]!=r[0])

						flag=false;

					}

				}

				

				if(i>0&&i<n-2)

				{

					if(s[i]=='o')

					{

						if(r[i]==1)

						r[i+1]=r[i-1];

						if(r[i]==0)

						r[i+1]=1-r[i-1];

					}

					if(s[i]=='x')

					{

						if(r[i]==1)

						r[i+1]=1-r[i-1];

						if(r[i]==0)

						r[i+1]=r[i-1];

					}

				}

				

				if(i==n-2)

				{

					if(s[i]=='o')

					{

						if(r[i]==1)

						if(r[i-1]!=r[i+1])

						flag=false;

						if(r[i]==0)

						if(r[i-1]==r[i+1])

						flag=false;

					}

					if(s[i]=='x')

					{

						if(r[i]==1)

						if(r[i-1]==r[i+1])

						flag=false;

						if(r[i]==0)

						if(r[i-1]!=r[i+1])

						flag=false;

					}

				}

			}

			/*for(int i=0;i<n;i++)

			printf("%d",r[i]);

			cout<<endl;*/

			if(flag)

			break;

			num++;

		}

		if(flag)

		for(int i=0;i<n;i++)

		{

			if(r[i]==1)

			printf("S");

			else printf("W");

		}

		else printf("-1");

		printf("\n");

	}

	return 0;

} 