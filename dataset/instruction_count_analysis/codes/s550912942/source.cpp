#include<cstdio>

#define int long long

int n;

main()

{

	scanf("%lld",&n);

	int i,j,t1,t2;

	for(i=1;i<=4000;++i)

		for(j=1;j<=4000;++j)

		{

			t1=n*i*j;

			t2=4*i*j-n*i-n*j;

			if(t2>0&&t1%t2==0)

			{

				printf("%lld %lld %lld\n",i,j,t1/t2);

				return 0;

			}

		}

}