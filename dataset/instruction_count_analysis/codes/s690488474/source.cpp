#include <cstdio>

#include <cstdlib>

#include <algorithm>



typedef long long LL;



double ans;



double calc(LL n,double sum)

{

	if(n == 1) return sum / (2 * n);

	else return calc(n - 1, sum - sum / (n * n)) + sum / (2 * n);

}

int main()

{

	LL n, d, x;

	

	scanf("%lld%lld%lld", &n, &d, &x);

	printf("%.10lf", calc(n, (2 * d + (2 * n - 1) * x) * n));

	return 0;

}