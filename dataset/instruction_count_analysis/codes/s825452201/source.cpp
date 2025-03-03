#include <cstdio>



const int MAXN = (1<<16);

const int MOD = int(1E9) + 7;



int pow_mod(int b, int p) {

	int ret = 1;

	while( p ) {

		if( p & 1 ) ret = 1LL*ret*b%MOD;

		b = 1LL*b*b%MOD;

		p >>= 1;

	}

	return ret;

}



int fct[MAXN + 5], ifct[MAXN + 5];

void init() {

	fct[0] = 1;

	for(int i=1;i<=MAXN;i++)

		fct[i] = 1LL*fct[i-1]*i%MOD;

	ifct[MAXN] = pow_mod(fct[MAXN], MOD - 2);

	for(int i=MAXN-1;i>=0;i--)

		ifct[i] = 1LL*ifct[i+1]*(i+1)%MOD;

}

int comb(int n, int m) {

	return 1LL*fct[n]*ifct[m]%MOD*ifct[n-m]%MOD;

}



int f[MAXN + 5], dp[MAXN + 5];

int lowbit(int x) {

	return x & -x;

}



int A[16], N, M, t;

int main() {

	init();

	scanf("%d%d", &N, &M), t = (1 << N);

	for(int i=0;i<M;i++)

		scanf("%d", &A[i]);

	dp[0] = f[0] = 1;

	for(int i=1;i<t;i++)

		f[i] = 1LL*comb(i, lowbit(i))*f[i^lowbit(i)]%MOD;

	for(int i=M-1;i>=0;i--) {

		for(int s=t-1;s>=0;s--) {

			int p = (t - A[i]) - s;

			for(int j=0;j<N;j++) {

				int q = (1 << j);

				if( !(s & q) && p >= q - 1 )

					dp[s|q] = (dp[s|q] + MOD - 1LL*dp[s]*comb(p,q-1)%MOD) % MOD;

			}

		}

	}

	int ans = 0;

	for(int i=0;i<t;i++) ans = (ans + 1LL*dp[i]*f[t-1-i]%MOD) % MOD;

	for(int i=0;i<N;i++) ans = 1LL*ans*fct[1 << i] % MOD;

	printf("%lld\n", 1LL*ans*t%MOD);

}