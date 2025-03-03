#include<cstdio>

#include<algorithm>

using namespace std;

int main()

{

    long N,x[100005],y[100005],t[100005],z;

	while(scanf("%ld",&N)!=EOF)

	{

		int flag=0;

		for(int i=0;i<N;i++)

			scanf("%ld%ld%ld",&t[i],&x[i],&y[i]);

		for(int i=0;i<N;i++)

		{

			z=t[i]-x[i]-y[i];

			if(t[i]<x[i]+y[i])

			{

				printf("No\n");

				flag=1;

				break;

			}

			else if(z%2!=0)

			{

				printf("No\n");

				flag=1;

				break;

			}			

		}

		if(flag==0)

		printf("Yes\n");

	}

	return 0;

}