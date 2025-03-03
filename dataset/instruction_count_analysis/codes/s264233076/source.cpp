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



	

	int N, M;

	cin >> N >> M;



	ll X[100001], Y[100001];

	rep(i, N) cin >> X[i];

	rep(i, M) cin >> Y[i];



	ll mod = 1e9 + 7;

	ll xtotal = 0;

	rep1(i, N - 1) {

		ll kari = ((X[i] - X[i - 1]) * i * (N - i)) % mod;

		xtotal = (xtotal + kari) % mod;

	}

	ll ytotal = 0;

	rep1(i, M - 1) {

		ll kari = ((Y[i] - Y[i - 1]) * i * (M - i)) % mod;

		ytotal = (ytotal + kari) % mod;

	}

	ll kotae = xtotal * ytotal % mod;



	co(kotae);



	Would you please return 0;

}