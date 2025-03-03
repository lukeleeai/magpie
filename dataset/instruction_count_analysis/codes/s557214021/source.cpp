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



	

	int N, T;

	cin >> N >> T;

	int A[100000];

	rep(i, N) cin >> A[i];



	int B[100000];

	B[0] = A[0];

	rep1(i, N - 1) {

		B[i] = min(B[i - 1], A[i]);

	}



	int mouke = 0;

	int siire, uru;

	rep1(i, N - 1) {

		if (A[i] - B[i] > mouke) {

			mouke = A[i] - B[i];

		}

	}



	int kosuto = 0;

	rep(i, N) {

		if (A[i] - B[i] == mouke) kosuto++;

	}



	co(kosuto);



	Would you please return 0;

}