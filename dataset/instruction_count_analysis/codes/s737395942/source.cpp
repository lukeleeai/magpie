#include <cstdio>

int n, t, a[305][305], b[305][305];

long long s;

int main() {

	int i, j, k;

	scanf("%d", &n);

	for(i=0; i<n; i++) for(j=0; j<n; j++) scanf("%d", &a[i][j]);

	for(k=0; k<n; k++) for(i=0; i<n; i++) for(j=0; j<n; j++) {

		t = a[i][k] + a[k][j];

		if(a[i][j]>t) {puts("-1"); return 0;}

		else if(a[i][j]==t && k!=i && k!=j) b[i][j] = 1;

	}

	for(i=0; i<n; i++) for(j=i+1; j<n; j++) s += a[i][j] * !b[i][j];

	printf("%lld", s);

	return 0;

}