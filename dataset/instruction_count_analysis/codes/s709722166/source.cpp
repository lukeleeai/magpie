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

	int B[100100] = {};

	rep1(i, N) {

		int A;

		cin >> A;

		B[A]++;

	}

	

	int OK = 1;

	if (N % 2) {

		if (B[0] != 1) OK = 0;

		rep1(i, N / 2) if (B[i * 2] != 2) OK = 0;

	}

	else {

		rep(i, N / 2) if (B[i * 2 + 1] != 2) OK = 0;

	}



	ll kotae = 1;

	ll mod = 1e9 + 7;

	rep(i, N / 2) {

		kotae = kotae * 2 % mod;

	}



	if (OK) co(kotae);

	else co(0);



	Would you please return 0;

}