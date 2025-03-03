#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#define ll long long

int line(const void*a,const void*b)

{

	return *(int *)a-*(ll *)b;

}

int main()

{

	ll s1[100010];

	ll judgesum[100010];

	ll a,n,sum;

	while(scanf("%lld",&n)!=EOF)

	{

		sum=0;

		for(a=1;a<=n;a++)

			scanf("%lld",&s1[a]);

		qsort(s1+1,n,sizeof(s1[1]),line);

		memset(judgesum,0,sizeof(judgesum));

		judgesum[1]=s1[1];

		for(a=2;a<=n;a++)

			judgesum[a]=judgesum[a-1]+s1[a];

		sum=1;

		for(a=n-1;a>=1;a--)

		{

			if(2*judgesum[a]>=s1[a+1])

				sum++;

            else break;

		}

		printf("%lld\n",sum);

	}

	return 0;

}
