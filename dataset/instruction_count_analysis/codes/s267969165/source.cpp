#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define pb push_back

#define mp make_pair

#define Would

#define you

#define please



void pakuri_sort(int N, int A[]) {

	const int b = 8;

	int tmp[30000];

	rep(k, 4) {

		int kazu[1 << b] = {}, kazu2[1 << b] = {};

		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];

		for (int i = N - 1; i >= 0; i--) tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];

		k++;

		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];

		for (int i = N - 1; i >= 0; i--) A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];

	}

}



int N, K;

int A[500];

inline bool keisan(int k) {

	int a[500];

	int ouchaku = 0;

	rep(j, N) {

		a[j] = A[j] % k;

		ouchaku = max(ouchaku, min(a[j], (k - a[j]) % k));

		if (ouchaku > K) return false;

	}

	pakuri_sort(N, a);

	int x = 0, y = N - 1;

	int tmp = a[0] + a[N - 1] - k;

	int kazu = a[0] + k - a[N - 1];

	while (x + 1 < y) {

		if (tmp <= 0) {

			tmp += a[++x];

			kazu += a[x];

		}

		else {

			tmp += a[--y] - k;

			kazu += k - a[y];

		}

	}

	if (kazu / 2 <= K) {

		printf("%d", k);

		return true;

	}

	return false;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	cin >> N >> K;

	int goukei = 0;

	rep(i, N) {

		cin >> A[i];

		goukei += A[i];

	}



	int yakusuu[30000];

	int M = 0;

	int sq = sqrt(goukei);

	rep1(i, sq) {

		if (goukei % i == 0) {

			yakusuu[M++] = i;

			if (i * i != goukei) {

				if (keisan(goukei / i)) return 0;

			}

		}

	}



	for (int i = M - 1; i >= 0; i--) {

		if (keisan(yakusuu[i])) return 0;

	}



	Would you please return 0;

}