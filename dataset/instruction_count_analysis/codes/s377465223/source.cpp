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





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	int A[200001];

	rep1(i, N) cin >> A[i];



	vector<int> kotae;

	int B[200001] = {};

	for (int i = N; i > 0; i--) {

		if (A[i] != B[i]) {

			cesp(i);

			cesp(A[i]);

			ce(B[i]);

			kotae.pb(i);

			int rt = sqrt(i);

			rep1(j, rt) {

				if (i % j == 0) {

					B[j] ^= 1;

					if(i != j * j) B[i / j] ^= 1;

				}

			}

		}

	}

	co(kotae.size());

	rep1(i, kotae.size()) {

		cosp(kotae[kotae.size() - i]);

	}



	Would you please return 0;

}