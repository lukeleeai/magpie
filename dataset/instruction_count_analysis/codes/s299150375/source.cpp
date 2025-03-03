#include <stdio.h>

#define N 200002

#define M 1000000007

typedef long long LL;





LL f[N], ans, invf[N], sum, t1, t2;



LL qpow(LL x, int y)

{

	if(!y) return 1;

	LL t = qpow(x, y >> 1);

	t = t * t % M;

	if(y & 1) t = t * x % M;

	return t;

}



int main()

{		

	int T, i, j, x, a, b, c, d, y, m, t;

	

	scanf("%d%d%d%d", &a, &b, &c, &d);

	x = a - c - 1, y = c - 1;

	m = b - d - 1 + y;

	t = b - 1 + x;

	if(t > m) m = t;

	f[0] = f[1] = 1;

	for(i = 2, j = 1; i <= m; j = i++){

		f[i] = f[j] * (LL)i % M;

	} 

	invf[m] = qpow(f[m], M - 2);

	for(i = m, j = m - 1; j >= 0; i = j--){

		invf[j] = invf[i] * (LL)i % M;

	}

	

	ans = invf[x] * invf[y] % M;

	for(i = d, sum = 0, j = b - 1 - d; i < b; i++, j--){

		t1 = f[i + x] * invf[i] % M;

		t2 = f[j + y] * invf[j] % M;

		sum += t1 * t2 % M;

	}

	ans = sum % M * ans % M;

	printf("%lld\n", ans);

			

	return 0;

}