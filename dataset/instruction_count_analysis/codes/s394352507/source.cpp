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



int hist[300002];



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	rep(i, N) {

		int a;

		cin >> a;

		hist[a]++;

	}

	sort(hist + 1, hist + N + 1);



	int k = N + 1;

	int ruiseki = N;

	int mae = 0;

	for (int i = N; i >= 1; i--) {

		while (hist[k - 1] >= i) {

			ruiseki -= hist[--k];

		}

		int ijou = N - k + 1;

		int kei = ijou + ruiseki / i;



		for (int j = mae + 1; j <= kei; j++) co(i);

		mae = kei;

	}

	for (int j = mae + 1; j <= N; j++) co(0);



	Would you please return 0;

}