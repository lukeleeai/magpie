// C.



#include <iostream>

#include <sstream>

#include <algorithm>

#include <numeric>

#include <vector>

#include <cstdio>

#include <cstdlib>

#include <cstring>



using namespace std;



typedef long long LL;



#ifdef __GNUC__

#define int128_t __int128

#else

typedef LL int128_t;

#endif



int main(int argc, char* argv[]) {

	LL x, k, d;

	cin >> x >> k >> d;

	if (x < 0) x = -x;

	LL r = (x + d - 1) / d;

	if (d >= x && k >= 9) {

		k = 8 + (k % 8);

	}

	int128_t X = x, K = k, D = d, kd = K * D;

	if (kd <= X) {

		x -= k * d;

		k = 0;

	} else if (k >= 100) {

		LL a = x % d;

		LL b = x - a;

		r = b / d;

		if (k >= r) {

			k -= r;

			x -= r * d;

			if (k >= 8) {

				k = 8 + (k % 8);

			}

		}

	}

	vector<LL> q;

	q.push_back(x);

	for (int t = 0; t < k; ++t) {

		vector<LL> nq;

		for (auto a : q) {

			nq.emplace_back(a - d);

			nq.emplace_back(a + d);

		}

		q = nq;

	}

	LL ans = 1LL << 60;

	for (auto a : q) {

		ans = min(ans, abs(a));

	}

	cout << ans << endl;

	return 0;

}
