#include <cstdio>

#include <string>

#include <utility>

#include <set>

#include <queue>

#include <algorithm>

using namespace std;

int nxt[200000], prv[200000];

bool OK[200000];

int main() {

	int N, M, Q;

	scanf("%d %d %d", &N, &M, &Q);

	for (int i = 0; i < N; i++) {

		nxt[i] = (i + 1) % N;

		prv[i] = (i - 1 + N) % N;

	}

	int cur = 0;

	for (int i = 0; i < M; i++) {

		int a;

		scanf("%d", &a);

		if (a & 1) {

			for (int j = 0; j < a; j++) {

				cur = prv[cur];

			}

		}

		else {

			for (int j = 0; j < a; j++) {

				cur = nxt[cur];

			}

		}

		nxt[prv[cur]] = nxt[cur];

		prv[nxt[cur]] = prv[cur];

		cur = nxt[cur];

	}

	OK[cur] = 1;

	int tmp = cur;

	for (cur = nxt[cur]; cur != tmp; cur = nxt[cur]) {

		OK[cur] = 1;

	}

	for (int i = 0; i < Q; i++) {

		int q;

		scanf("%d", &q);

		printf("%d\n", OK[q]);

	}

}