#include <stdio.h>

int N, M, Q, p, r, a, prv[200007], nxt[200007];

int main() {

	scanf("%d%d%d", &N, &M, &Q);

	for (int i = 0; i < N; i++) prv[i] = (i + N - 1) % N, nxt[i] = (i + 1) % N;

	for (int i = 0; i < M; i++) {

		scanf("%d", &a);

		for (int j = 0; j < a; j++) p = a % 2 ? prv[p] : nxt[p];

		nxt[prv[p]] = nxt[p], prv[nxt[p]] = prv[p];

		r = nxt[p], prv[p] = nxt[p] = -1, p = r;

	}

	for (int i = 0; i < Q; i++) scanf("%d", &a), puts(prv[a] != -1 ? "1" : "0");

	return 0;

}