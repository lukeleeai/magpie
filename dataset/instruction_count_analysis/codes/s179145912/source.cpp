#include <cstdio>

#include <cstdlib>

#include <algorithm>



typedef long long LL;



const int maxn = 1e6 + 20;

const int mod = 1e9 + 7;



int N, M, K, sum;

LL fac[maxn];

LL inv[maxn];

LL pw[maxn];

 

LL powermod(LL x,LL y)

{

	LL z = 1;

	

	while(y)

	{

		if(y & 1) z = z * x % mod;

		x = x * x % mod, y >>= 1;

	}

	

	return z;

}

LL combine(LL x,LL y)

{

	if(y < 0 || y > x) return 0;

	return fac[x] * inv[y] % mod * inv[x - y] % mod;

}

int main()

{

	scanf("%d%d%d", &N, &M, &K);

	sum = N + M + K;

	

	pw[0] = fac[0] = inv[0] = 1;

	for(int i = 1; i <= sum; i++)

	{

		pw[i] = pw[i - 1] * 3 % mod;

		fac[i] = fac[i - 1] * i % mod;

	}

	

	inv[sum] = powermod(fac[sum], mod - 2);

	for(int i = sum - 1; i >= 1; i--)

	{

		inv[i] = inv[i + 1] * (i + 1) % mod;

	}

	

	LL s = 1, ans = 0;

	

	for(int i = 0; i <= M + K; i++)

	{

		ans += s * combine(N - 1 + i, N - 1) % mod * pw[M + K - i] % mod;

		s = s * 2 - combine(i, M) - combine(i, K);

		s = (s % mod + mod) % mod;

	}

	ans %= mod;

	

	printf("%d", (int) ans);

	return 0;

}