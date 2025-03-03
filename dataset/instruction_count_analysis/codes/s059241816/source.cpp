#include<cstdio>

int main()

{

	long long m,n,ans;

	scanf("%lld %lld",&m,&n);

	if(m>=2)

		m-=2;

	if(n>=2)

		n-=2;

	ans=m*n;

	printf("%lld\n",ans);

	return 0;

}
