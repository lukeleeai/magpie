#include<cstdio>

#include<algorithm>

#include<cmath>

#define MOD 1000000007

using namespace std;

long long n,m;

int main()

{

	scanf("%lld%lld",&n,&m);

	if(abs(n-m)>1) {puts("0");return 0;}

	long long n1=1,n2=1;

	for(long long i=2;i<=n;++i) n1=(n1*i)%MOD;

	for(long long i=2;i<=m;++i) n2=(n2*i)%MOD;

	if(n!=m) printf("%lld\n",n1*n2%MOD);

	else printf("%lld\n",n1*n2*2%MOD);

	return 0;

}