#include "stdc++.h"

#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)

#define per(i,n) for ((i)=n;(i)>=(1);(i)--)

using namespace std;

int t,a,b,c,d,k;

int calc(int x)

{

	return (a-(b-x+k-1)/k)/k;

}

int main()

{

	int i;

	scanf("%d",&t);

	while(t--)

	{

		scanf("%d%d%d%d",&a,&b,&c,&d);

		k=(max(a,b)+min(a,b))/(min(a,b)+1);

		if(k==1)

		{

			for(i=c;i<=d;i++)

			{

				putchar('A'+((i&1)^(a>=b)));

			}

			puts("");

			continue;

		}

		int l=0,r=b+1,mid,ans=0;

		while(l<r)

		{

			mid=(l+r)/2;

			if(mid<=calc(mid))

			{

				l=mid+1;

				ans=mid;

			}

			else r=mid;

		}

		int lim=ans+a-(b-ans+k-1)/k+1;

		for(i=c;i<=d;i++)

		{

			if(i<=lim)

			{

				putchar('A'+(i%(k+1)==0));

			}

			else

			{

				putchar('A'+((a+b-i)%(k+1)!=k));

			}

		}

		puts("");

	}

	return 0;

}