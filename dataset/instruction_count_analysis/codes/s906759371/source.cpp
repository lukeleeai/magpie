#include <stdio.h>

#include <math.h>

typedef long long ll;

int main()

{

	ll N;

	scanf("%lld",&N);

	int flag=0;

	for(ll h=1;h<=3500;h++)

	{

		if (flag) break;

		for(ll n=1;n<=3500;n++)

		{

			if(flag) break;

			if(N-4*n>0) continue;

				ll de=4*h*n-N*(h+n);

				ll bde=N*h*n;

				if(de<=0||bde<=0) continue;

				if(de>0&&bde>0&&bde%de==0)

				{

					printf("%lld %lld %lld\n",h,n,bde/de);

					flag=1; 

				} 

				

				

		}

		

	}

	return 0;

}