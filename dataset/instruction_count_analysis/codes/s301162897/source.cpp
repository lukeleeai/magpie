#include <cstdio>



const int MOD = 924844033;

const int MAXN = 2000;



inline int add(int x, int y) {return (x + y >= MOD ? x + y - MOD : x + y);}

inline int sub(int x, int y) {return (x - y < 0 ? x - y + MOD : x - y);}

inline int mul(int x, int y) {return 1LL * x * y % MOD;}



int fct[MAXN + 5];

int f[2][2][MAXN + 5], h[2][2][MAXN + 5], g[MAXN + 5], t;

void init() {

	fct[0] = 1;

	for(int i=1;i<=MAXN;i++)

		fct[i] = mul(fct[i-1], i);

	g[t = 0] = 1;

}



void insert(int m) {

	for(int i=0;i<=t;i++)

		f[0][0][i] = f[0][1][i] = f[1][1][i] = 0, f[1][0][i] = g[i];

	for(int i=1;i<=m;i++) {

		for(int j=0;j<=t;j++)

			for(int p=0;p<=1;p++)

				for(int q=0;q<=1;q++)

					h[p][q][j] = f[p][q][j], f[p][q][j] = 0;

		t++, f[0][0][t] = f[0][1][t] = f[1][0][t] = f[1][1][t] = 0;

		for(int j=0;j<=t;j++)

			for(int p=0;p<=1;p++)

				for(int q=0;q<=1;q++) {

					f[q][0][j] = add(f[q][0][j], h[p][q][j]);

					if( p == 0 ) {

						f[q][0][j+1] = sub(f[q][0][j+1], h[p][q][j]);

						f[q][1][j+1] = sub(f[q][1][j+1], h[p][q][j]);

					}

					else f[q][1][j+1] = sub(f[q][1][j+1], h[p][q][j]);

				}

	}

	for(int i=0;i<=t;i++) g[i] = add(f[0][0][i], f[1][0][i]);

}



int a[MAXN + 5], N, K;

int main() {

	init(), scanf("%d%d", &N, &K);

	for(int i=1;i<=N;i++) a[i % K]++;

	for(int i=0;i<K;i++) insert(a[i]);

	int ans = 0;

	for(int i=0;i<=N;i++)

		ans = add(ans, mul(fct[N-i], g[i]));

	printf("%d\n", ans);

}