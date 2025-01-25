#include <iostream>

using namespace std;

int N, M, L, R, s[50003], t[50003], e[50003], c[10003]; long long d[10003];

int main() {

	cin >> N >> M;

	while(true) {

		cin >> s[R] >> t[R] >> e[R]; s[R]--, t[R]--;

		if (!e[R]) break; R++;

	}

	cin >> L;

	for (int i = 0; i < L; i++) {

		for (int j = 0; j < M; j++) cin >> c[j];

		for (int j = 0; j < N; j++) d[j] = 0;

		for (int j = 0; j < R; j++) d[s[j]] += c[t[j]] * e[j];

		for (int j = 0; j < N; j++) cout << (j ? " " : "") << d[j];

		cout << endl;

	}

}