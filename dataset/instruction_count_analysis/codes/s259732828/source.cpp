#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

#include"stdc++.h"

#include<cstdio>

#include<algorithm>

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



ll maeA[200001], maeB[200001];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	ll N, X, D;

	cin >> N >> X >> D;

	if (D == 0) {

		if (X == 0) printf("1");

		else printf("%lld", N + 1);

		return 0;

	}



	if (D < 0) {

		D *= -1;

		X *= -1;

	}



	ll R = (X ? D / __gcd(abs(X), D) : 1);

	ll Z = (X ? X / __gcd(abs(X), D) : 0);

	int r = 0;

	ll zure = 0;

	ll a = 0;

	ll b = 0;

	ll kotae = 0;

	rep(i, min(N + 1, R)) {

		maeA[i] = a + zure;

		maeB[i] = b + zure;

		kotae += maeB[i] - maeA[i] + 1;

		a += i;

		b += N - i - 1;

		r++;

	}

	r = 0;

	zure += Z;

	for (int i = min(N + 1, R); i <= N; i++) {

		ll A = a + zure;

		ll B = b + zure;

		if (maeA[r] >= A && maeB[r] <= B) {

			kotae += B + maeA[r] - A - maeB[r];

		}

		else if (maeA[r] <= A && maeB[r] >= B) {

			break;

		}

		else if (maeA[r] <= A) {

			kotae += B - max(maeB[r] + 1, A) + 1;

		}

		else {

			kotae += min(maeA[r] - 1, B) - A + 1;

		}

		maeA[r] = A;

		maeB[r] = B;



		a += i;

		b += N - i - 1;

		r++;

		if (r >= R) {

			r = 0;

			zure += Z;

		}

	}

	printf("%lld", kotae);



	Would you please return 0;

}