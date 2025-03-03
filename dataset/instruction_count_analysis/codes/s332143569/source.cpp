#include <stdio.h>

#define M 1000000007

typedef long long LL;



int main()

{		

	int n, m, d, i;

	LL f, t, ans;

	

	scanf("%d%d", &n, &m);

	if(n < m) n ^= m, m ^= n, n ^= m;

	d = n - m;

	if(d > 1){

		puts("0");

		return 0;

	}

	for(i = 1, f = 1; i < n; i++){

		f = f * (LL)i % M;

	}

	t = f * (LL)n % M;

	

	if(!d) ans = t * t * 2 % M;

	else ans = t * f % M;

	printf("%lld\n", ans);	

			

	return 0;

}