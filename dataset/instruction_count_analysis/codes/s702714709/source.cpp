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





	int N;

	cin >> N;

	ll K;

	cin >> K;



	int sei[200000], fu[200000];

	int seik = 0, fuk = 0;

	int zero = 0;

	rep(i, N) {

		int a;

		cin >> a;

		if (a > 0) sei[seik++] = a;

		else if (a < 0) fu[fuk++] = -a;

		else zero++;

	}

	sort(sei, sei + seik);

	sort(fu, fu + fuk);

	ll k0 = ll(seik) * fuk + ll(zero) * (zero - 1) / 2 + ll(zero) * (N - zero);



	ll L = -1000000000000000001, R = 1000000000000000000;

	while (L + 1 < R) {

		ll M = (L + R) / 2;

		ll k = 0;

		if (M >= 0) {

			k += k0;

			int i = 1;

			while (i < seik) {

				if (ll(sei[i]) * sei[i - 1] > M) break;

				k += i;

				i++;

			}

			int j = i - 1;

			while (i < seik) {

				while (j >= 1 && ll(sei[i]) * sei[j - 1] > M) j--;

				k += j;

				i++;

			}

			i = 1;

			while (i < fuk) {

				if (ll(fu[i]) * fu[i - 1] > M) break;

				k += i;

				i++;

			}

			j = i - 1;

			while (i < fuk) {

				while (j >= 1 && ll(fu[i]) * fu[j - 1] > M) j--;

				k += j;

				i++;

			}

		}

		else {

			int j = 0;

			rep(i, seik) {

				while (j < fuk && ll(sei[i]) * fu[fuk - j - 1] >= -M) j++;

				k += j;

			}

		}

		if (k >= K) R = M;

		else L = M;

	}



	co(R);



	Would you please return 0;

}