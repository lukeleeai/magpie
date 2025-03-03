//#pragma GCC optimize ("O3")

//#pragma GCC target ("avx")

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





	int N, M;

	cin >> N >> M;



	if (N % 2) {

		rep1(i, M) {

			cosp(i);

			co(N - i);

		}





	}

	else {

		int n = N / 2;

		rep1(i, (M + 1) / 2) {

			cosp(i);

			co(N - i + 1);







		}

		for (int i = (M + 1) / 2 + 1; i <= M; i++) {

			cosp(i);

			co(N - i);

		}

	}







	Would you please return 0;

}