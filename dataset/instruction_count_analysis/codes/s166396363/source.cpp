#include <cstdio>



const int MAXN = 400;

const int MOD = 998244353;



int pow_mod(int b, int p) {

	int ret = 1;

	for(int i=p;i;i>>=1,b=1LL*b*b%MOD)

		if( i & 1 ) ret = 1LL*ret*b%MOD;

	return ret;

}



int fct[MAXN + 5], ifct[MAXN + 5];

void init() {

	fct[0] = 1;

	for(int i=1;i<=MAXN;i++)

		fct[i] = 1LL*fct[i-1]*i%MOD;

	ifct[MAXN] = pow_mod(fct[MAXN], MOD-2);

	for(int i=MAXN-1;i>=0;i--)

		ifct[i] = 1LL*ifct[i+1]*(i+1)%MOD;

}



int A[MAXN + 5], B[MAXN + 5], SA, SB;



int f[2][2][MAXN + 5][MAXN + 5];



int main() {

	init();

	int N; scanf("%d", &N);

	for(int i=1;i<=N;i++)

		scanf("%d%d", &A[i], &B[i]), B[i];

	f[0][0][0][0] = 1;

	for(int i=1;i<=N;i++) {

		for(int j=0;j<=SA;j++)

			for(int k=0;k<=SB;k++)

				f[1][0][j][k] = f[0][0][j][k], f[1][1][j][k] = f[0][1][j][k];

		for(int j=0;j<=SA;j++)

			for(int k=0;k<=SB;k++) {

				int t = 1;

				for(int p=0;p<=B[i];p++,t=1LL*t*A[i]%MOD) {

					if( p == B[i] ) {

						int d = (MOD - 1LL*t*ifct[p-1]%MOD*f[1][0][j][k]%MOD)%MOD;

						f[0][1][j+A[i]][k+p] = (f[0][1][j+A[i]][k+p] + d)%MOD;

					}

					else {

						int d = (MOD - 1LL*t*ifct[p]%MOD*f[1][0][j][k]%MOD)%MOD;

						f[0][0][j+A[i]][k+p] = (f[0][0][j+A[i]][k+p] + d)%MOD;

						d = (MOD - 1LL*t*ifct[p]%MOD*f[1][1][j][k]%MOD)%MOD;

						f[0][1][j+A[i]][k+p] = (f[0][1][j+A[i]][k+p] + d)%MOD;

					}

				}

			}

		SA += A[i], SB += B[i];

	}

	int ans = 0;

	for(int i=1;i<=SA;i++)

		for(int j=1;j<=SB;j++) {

			int d = 1LL*f[0][1][i][j]*fct[j-1]%MOD*j%MOD*pow_mod(i,MOD-1-j-1)%MOD;

			ans = (ans + d)%MOD;

		}

	printf("%lld\n", 1LL*SA*(MOD - ans)%MOD);

}