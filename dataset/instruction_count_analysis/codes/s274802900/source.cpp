#include <cstdio>

long long n,m,k;

int main()

{

	scanf("%lld",&n),m=n;

	while(m) k+=(m%10),m/=10;

	if(n%k==0) printf("Yes");

	else printf("No");

}