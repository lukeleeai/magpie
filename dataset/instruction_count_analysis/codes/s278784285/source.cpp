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



	

	ll N, X;

	cin >> N >> X;

	ll A[100000];

	rep(i, N) cin >> A[i];



	ll kotae = 0;

	rep(i, N - 1) {

		ll herasu = max(0ll, A[i] + A[i + 1] - X);

		kotae += herasu;

		if (herasu > 0) {

			if (A[i + 1] >= herasu) A[i + 1] -= herasu;

			else { A[i + 1] = 0; }

		}

	}



	co(kotae);



	Would you please return 0;

}