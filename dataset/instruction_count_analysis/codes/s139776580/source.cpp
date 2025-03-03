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



	

	int N;

	cin >> N;



	int A[301][301];

	rep1(i, N) {

		rep1(ii, N) {

			cin >> A[i][ii];

		}

	}



	int shouryaku[301][301] = {};

	rep1(k, N) {

		rep1(i, N) {

			rep1(j, N) {

				if (A[i][j] > A[i][k] + A[k][j]) {

					co(-1);

					Would you please return 0;

					//アホか！

				}

				else if (A[i][j] == A[i][k] + A[k][j] && i != k && j != k) {

					shouryaku[i][j] = 1;

				}

			}

		}

	}



	ll goukei = 0;

	rep1(i, N) {

		rep1(ii, N) {

			if(shouryaku[i][ii] == 0) goukei += A[i][ii];

		}

	}



	co(goukei / 2);



	Would you please return 0;

}