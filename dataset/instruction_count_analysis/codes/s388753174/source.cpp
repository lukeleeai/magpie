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

	ll A[100001] = {};

	rep1(i, N) {

		cin >> A[i];

		A[i] += A[i - 1];

	}

	ll k1[2] = {};

	ll k2[2] = {};



	rep1(i, N) {

		if (i % 2) {

			if (A[i] - k1[0] + k1[1] <= 0) k1[1] += 1 - A[i] + k1[0] - k1[1];

			if (A[i] - k2[0] + k2[1] >= 0) k2[0] += 1 + A[i] - k2[0] + k2[1];

		}

		else {

			if (A[i] - k1[0] + k1[1] >= 0) k1[0] += 1 + A[i] - k1[0] + k1[1];

			if (A[i] - k2[0] + k2[1] <= 0) k2[1] += 1 - A[i] + k2[0] - k2[1];

		}



	}



	ll kotae = min(k1[0] + k1[1], k2[0] + k2[1]);

	co(kotae);



	Would you please return 0;

}