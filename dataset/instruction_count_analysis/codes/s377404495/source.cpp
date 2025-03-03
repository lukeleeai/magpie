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





int BIT[200001];



void add(ll A) {

	while (A > 0) {

		BIT[A]++;

		A -= A & -A;

	}

}



int query(int A) {

	int kotae = 0;

	while (A <= 200000) {

		kotae += BIT[A];

		A += A & -A;

	}

	return kotae;

}





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	string S;

	cin >> S;

	int N = S.size();

	int A[26] = {};

	rep(i, N) {

		A[S[i] - 'a']++;

	}

	int kisuu = 0;

	rep(i, 26) {

		if (A[i] % 2) kisuu++;

	}

	if (kisuu > 1) co(-1);

	else {

		vector<int> V1[26], V2[26];

		rep(i, N) {

			V1[S[i] - 'a'].pb(i);

			V2[S[i] - 'a'].pb(N - 1 - i);

		}

		int used[200001] = {};

		int kazu = 0;

		ll kotae = 0;

		int atta = 0;

		rep(i, N) {

			if (kazu * 2 >= N - 1) break;

			if (used[i] == 0) {

				int kari1 = V1[S[i] - 'a'].back();

				int kari2 = V2[S[i] - 'a'].back();

				if (i + kari2 == N - 1) {

					atta = 1;

					continue;

				}

				kotae += kari2 - query(kari1) + atta;

				used[kari1] = 1;

				add(kari1);

				V1[S[i] - 'a'].pop_back();

				V2[S[i] - 'a'].pop_back();

				kazu++;

			}

		}

		co(kotae);

	}



	Would you please return 0;

}
