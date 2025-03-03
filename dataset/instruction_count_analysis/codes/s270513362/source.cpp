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

	string S;

	cin >> S;





	int OK = 1;

	rep(i, 4) {

		int A[100001];

		A[0] = i % 2;

		A[1] = i / 2 % 2;



		for (int ii = 1; ii < N - 1; ii++) {

			if (S[ii] == 'o') {

				if (A[ii] % 2) A[ii + 1] = A[ii - 1];

				else A[ii + 1] = A[ii - 1] + 1;

			}

			else {

				if (A[ii] % 2) A[ii + 1] = A[ii - 1] + 1;

				else A[ii + 1] = A[ii - 1];

			}

		}



		rep(i, N) A[i] = A[i] % 2;



		OK = 1;

		if (S[N - 1] == 'o') {

			if (A[N - 1]) {

				if (A[N - 2] != A[0]) OK = 0;

			}

			else {

				if (A[N - 2] == A[0]) OK = 0;

			}

		}

		else {

			if (A[N - 1]) {

				if (A[N - 2] == A[0]) OK = 0;

			}

			else {

				if (A[N - 2] != A[0]) OK = 0;

			}

		}



		if (S[0] == 'o') {

			if (A[0]) {

				if (A[N - 1] != A[1]) OK = 0;

			}

			else {

				if (A[N - 1] == A[1]) OK = 0;

			}

		}

		else {

			if (A[0]) {

				if (A[N - 1] == A[1]) OK = 0;

			}

			else {

				if (A[N - 1] != A[1]) OK = 0;

			}

		}



		if (OK) {

			rep(i, N) {

				if (A[i]) cout << 'S';

				else cout << 'W';

			}

			cout << endl;

			break;

		}

	}



	if (OK == 0) co(-1);

	Would you please return 0;

}