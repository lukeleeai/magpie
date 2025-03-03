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



//ほんと全く分からなかったなぁ



ll mod = 1e9 + 7;



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, M;

	cin >> N >> M;

	int A[1000], B[1000];

	rep(i, N) cin >> A[i];

	rep(i, M) cin >> B[i];

	sort(A, A + N);

	reverse(A, A + N);

	sort(B, B + M);

	reverse(B, B + M);



	int Aima = 0;

	int Bima = 0;

	ll kotae = 1;

	int nokori = 0;



	for (int i = N * M; i >= 1; i--) {

		if (Aima != N && A[Aima] == i && Bima != M && B[Bima] == i) {

			nokori += Aima + Bima;

			Aima++;

			Bima++;

		}

		else if (Aima != N && A[Aima] == i) {

			kotae = kotae * Bima % mod;

			nokori += Bima - 1;

			Aima++;

		}

		else if (Bima != M && B[Bima] == i) {

			kotae = kotae * Aima % mod;

			nokori += Aima - 1;

			Bima++;

		}

		else {

			kotae = kotae * nokori % mod;

			nokori--;

		}

		if (Aima != N && A[Aima] == i) kotae = 0;

		if (Bima != M && B[Bima] == i) kotae = 0;

	}



	co(kotae);



	Would you please return 0;

}