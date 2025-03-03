#include <stdio.h>

#include <math.h>

#define N 1000001

#define M 1000000007

typedef long long LL;



int mp[N], pc[N];

int a[10001], m = 0;



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

	int n, i, j, x, k, p[22], c, y, tc;

	LL e = 1, s = 0;

	

	scanf("%d", &n);

	for(i = 0; i < n; i++){

		scanf("%d", &x);

		if(x > m) m = x;

		a[i] = x;

	}

	for(i = 0; i <= m; i++) mp[i] = pc[i] = 0;

	for(i = 2, k = sqrt(m); i <= k; i++){

		if(mp[i]) continue;

		for(j = i * i; j <= m; j += i){

			if(!mp[j]) mp[j] = i;

		}

	}

	for(i = 1; i <= m; i++){

		if(!mp[i]) mp[i] = i;

	}

	for(i = 0; i < n; i++){

		x = a[i];

		if(x == 1) continue;

		c = 0;

		while(x > 1){

			p[c++] = mp[x];

			x /= mp[x];

		}

		for(j = 0; j < c; j = k){

			for(y = p[j], k = j + 1; k < c && p[k] == y; k++);

			tc = k - j;

			if(pc[y] < tc) pc[y] = tc;

		}

	}

	for(i = 2; i <= m; i++){

		if(pc[i]) e = e * qpow((LL)i, pc[i]) % M;

	}

	for(i = 0; i < n; i++){

		s += e * qpow((LL)a[i], M - 2) % M;

	}

	printf("%lld\n", s %= M);

			

	return 0;

}