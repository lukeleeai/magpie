//#pragma GCC optimize ("O3")

//#pragma GCC target ("avx2")

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





	int N, A, B, C;

	cin >> N >> A >> B >> C;



	int kei = A + B + C;



	if (kei != 2) {

		int OK = 1;



		vector<char> kotae;

		rep(i, N) {

			string S;

			cin >> S;



			if (S == "AB") {

				if (A == 0 && B == 0) OK = 0;

				if (A <= B) {

					kotae.pb('A');

					A++;

					B--;

				}

				else {

					kotae.pb('B');

					B++;

					A--;

				}

			}

			else if (S == "BC") {

				if (C == 0 && B == 0) OK = 0;

				if (C <= B) {

					kotae.pb('C');

					C++;

					B--;

				}

				else {

					kotae.pb('B');

					B++;

					C--;

				}

			}

			else {

				if (A == 0 && C == 0) OK = 0;

				if (A <= C) {

					kotae.pb('A');

					A++;

					C--;

				}

				else {

					kotae.pb('C');

					C++;

					A--;

				}

			}

		}

		if (OK) {

			co("Yes");

			for (auto C : kotae) co(C);

		}

		else co("No");

	}

	else {

		int OK = 1;



		vector<char> kotae;

		string S[100001];

		rep(i, N) cin >> S[i];



		rep(i, N) {



			if (S[i] == "AB") {

				if (A == 0 && B == 0) OK = 0;

				if (A == 1 && B == 1) {

					if (i == N - 1 || S[i + 1] == "BC") {

						kotae.pb('B');

						B++;

						A--;

					}

					else {

						kotae.pb('A');

						A++;

						B--;

					}

				}

				else if (A <= B) {

					kotae.pb('A');

					A++;

					B--;

				}

				else {

					kotae.pb('B');

					B++;

					A--;

				}

			}

			else if (S[i] == "BC") {

				if (C == 0 && B == 0) OK = 0;

				if (C == 1 && B == 1) {

					if (i == N - 1 || S[i + 1] == "AC") {

						kotae.pb('C');

						C++;

						B--;

					}

					else {

						kotae.pb('B');

						B++;

						C--;

					}

				}

				else if (C <= B) {

					kotae.pb('C');

					C++;

					B--;

				}

				else {

					kotae.pb('B');

					B++;

					C--;

				}

			}

			else {

				if (A == 0 && C == 0) OK = 0;

				if (A == 1 && C == 1) {

					if (i == N - 1 || S[i + 1] == "BC") {

						kotae.pb('C');

						C++;

						A--;

					}

					else {

						kotae.pb('A');

						A++;

						C--;

					}

				}

				else if (A <= C) {

					kotae.pb('A');

					A++;

					C--;

				}

				else {

					kotae.pb('C');

					C++;

					A--;

				}

			}

		}

		if (OK) {

			co("Yes");

			for (auto C : kotae) co(C);

		}

		else co("No");

	}





	Would you please return 0;

}