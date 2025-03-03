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



//よくわかんないけど通った？



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, K;

	cin >> N >> K;

	int H[302] = {};

	rep1(i, N) cin >> H[i];

	ll hutuu = 0;

	rep(i, N + 1) {

		if (H[i + 1] > H[i]) hutuu += H[i + 1] - H[i];

	}



	ll dp[302][601] = {};

	rep(i, N + 1) {

		auto dpi = dp[i];

		ll tmp1 = max(0, H[i + 1] - H[i]);

		ll tmp2 = max(0, H[i] - H[i + 1]);

		ll tmp3 = min(tmp1, tmp2);

		int mae = H[i + 1];

		ll maetmp = tmp3;

		for (int j = i + 2; j <= N + 1; j++) {

			if (mae < H[j]) tmp1 += H[j] - mae;

			if (mae > H[j]) tmp2 += mae - H[j];

			tmp3 = min(tmp1, tmp2);

			if (maetmp < tmp3) {

				int k = j - i - 1;

				auto dpj = dp[j] + k;

				rep(p, K) chmax(dpj[p], dpi[p] + tmp3);

			}

			mae = H[j];

			maetmp = tmp3;

		}

		auto dpi2 = dp[i + 1];

		rep(p, K + 1) chmax(dpi2[p], dpi[p]);

	}

	co(hutuu - dp[N + 1][K]);





	Would you please return 0;

}