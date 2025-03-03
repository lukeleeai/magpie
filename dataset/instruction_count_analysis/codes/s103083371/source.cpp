#include<stdio.h>

long long int a[600000]={0};

#define mod 1000000007

int main()

{

	long long int n,i,j,s,ans,d;

	scanf("%lld",&n);

	for(i=1;i<=n;i++){

		scanf("%lld",&a[i]);

		

	} 

	d=1;ans=0;

	for(i=0;i<60;i++)

	{

		s=0;

		for(j=1;j<=n;j++)

		{



			if(a[j]&1)

			s++;

			a[j]>>=1;

		}



		ans+=((s*(n-s)%mod)*d)%mod;

		d*=2;

		d%=mod;

	}

	printf("%lld\n",ans%mod);

 } 