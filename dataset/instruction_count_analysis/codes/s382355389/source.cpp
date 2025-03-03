#include<cstdio>

#include<algorithm>

using namespace std;

int result(int a,int b,int m)

{

	long long  d=1,t=a;

	while(b)

	{

		if(b&1)

		d=(d*t)%m;

		b/=2;

		t=(t*t)%m;

	}

	return d;

}                        

int a[100010];

int main()

{

	int n;

	while(scanf("%d",&n)!=EOF)

	{

		for(int i = 1; i <= n; i++)

		{

			scanf("%d",&a[i]);

			

		}

		sort(a+1,a+n+1);

		int f=1;

		if(n%2==1)

		{

			for(int i = 1; i <= n; i++)

			{

				if(i%2==0)

				{

					if(a[i]!=i)

					{

						f=0;break;

					}

				}

				else

				{

					if(a[i]!=i-1)

					{

						f=0;break;

					}

				}

			}	

		}

		else

		{

			for(int i = 1; i <= n; i++)

			{

				if(i%2==0)

				{

					if(a[i]!=i-1)

					{

						f=0;break;

					}

				}

				else

				{

					if(a[i]!=i)

					{

						f=0;break;

					}

				}

			}	

		}

		if(f==0)

		printf("0\n");

		else

		{

			printf("%d\n",result(2,n/2,1000000007));

		}

	}

	return 0;

}