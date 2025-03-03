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



const int mod = 998244353;

const int IMAX = 100000;

constexpr ll modpow(ll A, ll B) {

	ll kotae = 1;

	while (B > 0) {

		if (B & 1) kotae = kotae * A % mod;

		A = A * A % mod;

		B >>= 1;

	}

	return kotae;

}



ll dp[3001];

int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, S;

	cin >> N >> S;



	int A[3000];

	rep(i, N) cin >> A[i];

	sort(A, A + N);



	ll k2 = modpow(2, mod - 2);

	dp[0] = modpow(2, N);

	int s = 0;

	rep(i, N) {

		s = min(S, s + A[i]);

		for (int j = s; j >= A[i]; j--) {

			dp[j] = (dp[j] + dp[j - A[i]] * k2) % mod;

		}

	}



	co(dp[S] % mod);



	Would you please return 0;

}