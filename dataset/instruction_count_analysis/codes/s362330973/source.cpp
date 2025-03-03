#include <cstdio>

#define N 2010

#define INF 1e18

long long n, m, a[N], b[N], c[N], d[N/2];

int main() {

	int i, j;

	scanf("%lld%lld", &n, &m);

	for(i=0; i<m; i++) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);

	for(i=1; i<=n; i++) d[i] = -INF;

	d[1] = 0;

	for(i=0; i<n; i++) for(j=0; j<m; j++) {

		if(d[a[j]] != -INF && d[b[j]] < d[a[j]] + c[j]) {

			d[b[j]] = d[a[j]] + c[j];

			if(i==n-1 && b[j]==n) d[0] = 1;

		}

	}

	d[0] ? puts("inf") : printf("%lld", d[n]);

	return 0;

}