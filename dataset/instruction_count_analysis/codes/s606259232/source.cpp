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





	ll N;

	cin >> N;

	ll A[100000];

	rep(i, N) cin >> A[i];

	

	ll sum = 0;

	rep(i, N) sum += A[i];



	int OK = 1;

	if (sum % (N * (N + 1) / 2)) OK = 0;

	else {

		ll k = sum / (N * (N + 1) / 2);

		rep(i, N) {

			A[i] -= k * (i + 1);

		}

		ll kazu = 0;

		rep(i, N - 1) {

			if ((A[i] - A[i + 1]) % N || A[i] < A[i + 1]) OK = 0;

			else {

				kazu += (A[i] - A[i + 1]) / N;

			}

		}

		if ((A[0] - A[N - 1]) % N) OK = 0;

		else {

			if (kazu > k) OK = 0;

		}

	}



	if (OK) co("YES");

	else co("NO");





	Would you please return 0;

}