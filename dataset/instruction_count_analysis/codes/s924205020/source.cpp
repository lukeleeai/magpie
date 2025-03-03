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

	int tmp[1 << 18];

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



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	int n = (1 << N);

	int S[1 << 18];

	rep(i, (1 << N)) {

		cin >> S[i];

	}

	pakuri_sort(n, S);

	int A[1 << 17];

	A[0] = S[n - 1];

	int OK = 1;

	rep(i, N - 1) {

		int p = n - (1 << i);

		for (int j = (1 << i) - 1; j >= 0; j--) {

			while (p >= 0 && S[p] >= A[j]) p--;

			if (p < 0) {

				OK = 0;

				break;

			}

			A[j + (1 << i)] = S[p];

			S[p] = 1e9;

			p--;

		}

		if (!OK) break;

		pakuri_sort(n - (1 << i), S);

		pakuri_sort(1 << (i + 1), A);

	}

	int i = N - 1;

	int p = n - (1 << i);

	for (int j = (1 << i) - 1; j >= 0; j--) {

		while (p >= 0 && S[p] >= A[j]) p--;

		if (p < 0) {

			OK = 0;

			break;

		}

		S[p] = 1e9;

		p--;

	}



	if (OK) co("Yes");

	else co("No");



	Would you please return 0;

}