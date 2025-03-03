#pragma GCC optimize("Ofast,unroll-loops")

#pragma GCC target("sse,sse2,sse3,ssse3")

#include "stdc++.h"



using namespace std;



typedef long long ll;



int cnt[4], fact[] = {1, 1, 2, 6};



vector <int> vec;



int main() {

	ios::sync_with_stdio(false);

	cin.tie(NULL);

	int n;

	string s;

	bool ans = 0;

	cin >> n >> s;

	for (int i = 0; i < n; ++i) {

		if ((i & (n - 1)) == i)

			ans = (ans + s[i] - 48) % 2;

	}

	for (int i = 1; i < n; ++i) {

		int q = s[i - 1] - 48, w = s[i] - 48;

		++cnt[abs(q - w)];

		vec.push_back(abs(q - w));

	}

	if (!cnt[1]) {

		int sum = 0;

		for (int i = 0; i < n - 1; ++i) {

			int q = i, w = n - 2, p = 1;

			while (q) {

				if ((w % 4) < (q % 4))

					p = 0;

				else

					p *= (fact[w % 4] / fact[q % 4] / fact[(w % 4) - (q % 4)]) % 4;

				q /= 4;

				w /= 4;

			}

			sum += p * vec[i];

			sum %= 4;

		}

		cout << sum << '\n';

	}

	else

		cout << ans << '\n';

}
