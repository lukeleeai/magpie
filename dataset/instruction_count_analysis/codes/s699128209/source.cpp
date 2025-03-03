#include <stdio.h>

#define N 2222222

#define M 1000000007

typedef long long LL;



LL f[N];



LL qpow(LL x, int y)

{

	if(!y) return 1;

	LL t = qpow(x, y >> 1);

	t = t * t % M;

	if(y & 1) t = t * x % M;

	return t;

}



LL S(int x, int y)

{

	LL ans = f[x + y + 2];

	ans = ans * qpow(f[y + 1], M - 2) % M;

	ans = ans * qpow(f[x + 1], M - 2) % M;

	return ans - 1;

}



int main() 

{

	int r1, c1, r2, c2, m, i, j;

	LL sum;

		

	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

	m = r2 + c2 + 2;

	for(i = 2, f[0] = f[j = 1] = 1; i <= m; j = i++){

		f[i] = f[j] * (LL)i % M;

	}

	sum = S(r2, c2) - S(r1 - 1, c2);

	if(sum < 0) sum += M;

	sum -= S(r2, c1 - 1);

	if(sum < 0) sum += M;

	sum += S(r1 - 1, c1 - 1);

	if(sum >= M) sum -= M;

	printf("%lld\n", sum);

		

	return 0;

}