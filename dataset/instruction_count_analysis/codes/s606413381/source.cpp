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



	

	int N, A, B;

	cin >> N >> A >> B;



	ll saidai = (ll)A * B;

	int saishou = A + B - 1;

	if (N < saishou || N > saidai) {

		co(-1);

		return 0;

	}

	

	int amari = N - B;

	vector<int> K;

	rep(i, B) {

		int kari = min(A - 1, amari);

		K.pb(kari);

		amari -= kari;

	}



	rep(i, B) {

		rep(j, K[i] + 1) {

			cosp(N - K[i] + j);

		}

		N -= K[i] + 1;

	}



	Would you please return 0;

}