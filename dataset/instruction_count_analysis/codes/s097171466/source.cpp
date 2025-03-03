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





	ll N, K;

	cin >> N >> K;

	int A[200000], F[200000];

	rep(i, N) cin >> A[i];

	rep(i, N) cin >> F[i];

	sort(A, A + N);

	sort(F, F + N);

	reverse(F, F + N);





	ll L = -1, R = 1e18;

	while (L + 1 < R) {

		ll M = (L + R) / 2;



		ll kazu = 0;

		rep(i, N) {

			if ((ll)A[i] * F[i] > M) {

				kazu += ((ll)A[i] * F[i] - M + F[i] - 1) / F[i];

			}

		}

		if (kazu <= K) R = M;

		else L = M;

	}



	co(R);





	Would you please return 0;

}