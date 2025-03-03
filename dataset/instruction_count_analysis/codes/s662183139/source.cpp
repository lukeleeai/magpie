#include<cstdio>

#include<algorithm>

using namespace std;

int D[5010], n, Mod, C[5010];

void Make(int t) {

	int i;

	for (i = 0; i <= n - t; i++) {

		D[i+t] = (D[i+t] + D[i]) % Mod;

	}

}

int main() {

	int i;

	scanf("%d%d", &n, &Mod);

	D[0] = 1;

	for (i = 2; i <= n; i++) {

		Make(min(i - 1, n + 2 - i));

	}

	int res = 0;

	for (i = 0; i < n; i++) {

		res = (res + 1ll * (n - i)*D[i]) % Mod;

	}

	printf("%d\n", res);

}