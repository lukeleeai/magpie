#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

int main()

{

	long long l,r;

	scanf("%lld %lld",&l,&r);

	if(l%2019==0||r%2019==0)

	{

		printf("0");

		return 0;

	}

	if(l/2019<r/2019)

	{

		printf("0");

		return 0;

	}

	long long pd=2019;

	for(long long i=l;i<=r;i++)

	{

		for(long long j=i+1;j<=r;j++)

		{

			pd=min(i*j%2019,pd);

		}

	}

	printf("%lld",pd);

	

}