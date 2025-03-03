#pragma GCC optimize ("O2")

#pragma GCC target ("avx2")

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





	int N;

	cin >> N;



	int A[200000];

	rep(i, N) cin >> A[i];

	sort(A, A + N);

	reverse(A, A + N);



	ll kotae = A[0];

	int K = N - 2;

	for (int p = 1; p < N; p++) {

		if (K > 0) {

			kotae += A[p];

			K--;

		}

		if (K > 0) {

			kotae += A[p];

			K--;

		}

	}



	co(kotae);









	Would you please return 0;

}