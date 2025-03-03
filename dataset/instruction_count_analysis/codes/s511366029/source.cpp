#include<cstdio>

int main()

{

	long long n,m;

	scanf("%lld%lld",&n,&m);

	long long ans=m-n*2;

	if(ans<0)

	{

		printf("%lld\n",m/2);

		return 0;

	} 

	printf("%lld\n",n+ans/4);

}