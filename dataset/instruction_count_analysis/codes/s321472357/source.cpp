#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define Would

#define you

#define please



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	string S;

	cin >> S;

	int N = S.size();

	int nokori = N - 1;

	int saigo = N;

	int kaisuu = (N - 2) / 2;

	int base = 2;

	if (S[0] == '0' || S[N - 1] == '1' || S[N - 2] == '0') {

		co(-1);

	}

	else {

		rep1(i, kaisuu) if (S[i] != S[N - i - 2]) {

			co(-1);

			return 0;

		}

		cosp(1);

		co(2);

		nokori--;



		rep(i, kaisuu) {

			if (S[i + 1] == '0') {

				cosp(base);

				co(saigo);

				saigo--;

				nokori--;

			}

			else {

				cosp(base);

				co(base + 1);

				base++;

				nokori--;

			}

		}

		rep1(i, nokori) {

			cosp(base);

			co(base + i);

		}

	}



	Would you please return 0;

}