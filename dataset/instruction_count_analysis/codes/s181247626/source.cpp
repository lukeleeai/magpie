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





	int K, N;

	cin >> K >> N;



	if (K % 2) {

		ll A[300001] = {};

		A[0] = 1;

		ll S[300001] = {};

		S[0] = A[0] * (K / 2) + 1;

		int doko;

		rep(i, N) {

			if (S[i] >= N / 2) {

				doko = i;

				break;

			}

			A[i + 1] = (A[i] * K) + 1;

			S[i + 1] = S[i] + A[i + 1] * (K / 2) + 1;

		}

		ll kazu = S[doko] - N / 2;

		

		vector<int> kotae;

		for (int i = N - 1; i >= 0; i--) {

			if (i > doko) kotae.pb((K + 1) / 2);

			else {

				if (kazu == 0) break;

				else {

					kazu--;

					ll kari = kazu / A[i];

					if (kari > K - 1) kari = K - 1;

					kazu -= kari * A[i];

					kotae.pb(kari + 1);

				}

			}

		}

		for (auto itr = kotae.begin(); itr < --kotae.end(); itr++) {

			cosp(*itr);

		}

		co(kotae.back());



	}

	else {

		if (N > 1) {

			cosp(K / 2);

			rep(i, N - 2) cosp(K);

			co(K);

		}

		else co(K / 2);

	}



	Would you please return 0;

}