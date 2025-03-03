#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

#define Would

#define you

#define please





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, M, V, P;

	cin >> N >> M >> V >> P;



	int A[100000];

	rep(i, N) cin >> A[i];

	sort(A, A + N);

	reverse(A, A + N);



	int L = 0, R = N;

	while (L + 1 < R) {

		int m = (L + R) / 2;

		int a = A[m] + M;

		if (P > V) {

			if (a >= A[P - 1]) L = m;

			else R = m;

		}

		else {

			ll amari = ll(V - P) * M;

			ll kari = 0;

			bool dame = 0;

			for (int i = P - 1; i < N; i++) {

				if (i != m) {

					if (a < A[i]) dame = 1;

					kari += min(M, a - A[i]);

				}

			}

			if (!dame && amari <= kari) {

				L = m;

			}

			else R = m;

		}

	}



	co(R);





	Would you please return 0;

}