#pragma GCC optimize ("O3")

#pragma GCC target ("avx2")

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





	ll N, K;

	cin >> N >> K;



	int A[200001];

	rep1(i, N) cin >> A[i];



	int D[200001] = {};

	int d = 1;

	int p = 1;



	while (D[p] == 0) {

		D[p] = d;



		p = A[p];

		d++;

	}



	int kuri = d - D[p];



	if (K > D[p]) {

		ll k = K - D[p];

		k %= kuri;

		K = D[p] + k;

	}



	rep1(i, N) D[i] = 0;

	d = 1;

	p = 1;

	while (d <= K) {

		D[p] = d;



		p = A[p];

		d++;

	}



	co(p);



	Would you please return 0;

}