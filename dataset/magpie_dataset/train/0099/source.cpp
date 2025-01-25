#include <iostream>

using namespace std;

int N, M, Q, p, r, a, prv[200007], nxt[200007];

int main() {

	cin >> N >> M >> Q;

	for (int i = 0; i < N; i++) prv[i] = (i + N - 1) % N, nxt[i] = (i + 1) % N;

	for (int i = 0; i < M; i++) {

		cin >> a;

		for (int j = 0; j < a; j++) p = a % 2 ? prv[p] : nxt[p];

		nxt[prv[p]] = nxt[p], prv[nxt[p]] = prv[p];

		r = nxt[p], prv[p] = nxt[p] = -1, p = r;

	}

	for (int i = 0; i < Q; i++) cin >> a, cout << (prv[a] != -1 ? 1 : 0) << endl;

	return 0;

}