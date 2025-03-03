#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define Would

#define you

#define please



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	int N, H;

	cin >> N >> H;

	int a[100000] = {};

	int b[100000] = {};

	rep(i, N) {

		cin >> a[i] >> b[i];

	}



	sort(a, a + N);

	sort(b, b + N);



	int saidai = a[N - 1];



	int kaisuu = 0;

	rep(i, N) {

		if (b[N - i - 1] > saidai) {

			kaisuu++;

			H -= b[N - i - 1];

			if (H <= 0) break;

		}

	}

	

	if (H > 0) {

		kaisuu += H / saidai;

		if (H % saidai) kaisuu++;

	}

	co(kaisuu);

	Would you please return 0;

}