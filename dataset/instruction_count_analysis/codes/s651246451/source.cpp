#include<cstdio>

#define LL long long

#define N 100010

LL n,m,a[N],b[N];

signed main()

{

	scanf("%lld%lld",&n,&m);LL x(0),y(0),mod(1e9+7);

	for(register int i(1);i<=n;i++)

		scanf("%lld",&a[i]);

	for(register int i(1);i<=m;i++)

		scanf("%lld",&b[i]);

	for(register int i(1),j(n);i<j;i++,j--)

		x=(x+(a[j]-a[i])*(j-i)%mod)%mod;

	for(register int i(1),j(m);i<j;i++,j--)

		y=(y+(b[j]-b[i])*(j-i)%mod)%mod;

	return printf("%lld\n",x*y%mod),0;

}