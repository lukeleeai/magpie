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





	ll N, L;

	cin >> N >> L;

	set<string> ST[100001];

	ll G = 0;

	rep(i, N) {

		string S;

		cin >> S;

		int M = S.size();

		ST[M].insert(S);

	}

	for (int i = 100000; i > 0; i--) {

		if (ST[i].size() & 1) {

			ll K = L - i + 1;

			ll GK = 1;

			while (K % 2 == 0) {

				GK <<= 1;

				K /= 2;

			}

			G ^= GK;

		}

		for (string S : ST[i]) {

			S.pop_back();

			ST[i - 1].insert(S);

		}

		ST[i].clear();

	}

	if (G) co("Alice");

	else co("Bob");



	Would you please return 0;

}
