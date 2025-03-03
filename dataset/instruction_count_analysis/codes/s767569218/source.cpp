#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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





	int N, K;

	cin >> N >> K;



	int P[200000];

	rep(i, N) cin >> P[i];



	ll saidai = 0;

	ll ima = 0;

	rep(i, K) ima += P[i] + 1;

	saidai = ima;



	for (int i = K; i < N; i++) {

		ima += P[i] + 1;

		ima -= P[i - K] + 1;

		chmax(saidai, ima);

	}



	double kotae = saidai * 0.5;



	cout << fixed << kotae << endl;





	Would you please return 0;

}