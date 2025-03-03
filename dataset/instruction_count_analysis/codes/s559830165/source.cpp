#include <stdio.h>

#define LL long long

LL ans;

int main(){

	int n,i,m,a,b;

	scanf("%d",&n);

	for(i=1;i<=n;i++){

		m=n/i;

		a=i,b=a+(m-1)*i;

		ans+=(LL)(a+b)*m/2;

	}

	printf("%lld\n",ans);

	return 0;

}