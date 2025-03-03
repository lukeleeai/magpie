#include"stdc++.h"

#define rep(i,n)for(int i=0;i<n;i++)

#define MOD 1000000007

#define INF 0x3f3f3f3f

#define INFL 0x3f3f3f3f3f3f3f3f

#define EPS (1e-10)

using namespace std;

typedef long long ll;

typedef pair<int, int>P;



bool used[1000000];

int main() {

	/*vector<int>v(7);

	iota(v.begin(), v.end(), 1);

	set<int>se;

	do {

		vector<int>d1, d2 = v;

		while (d2.size() > 1) {

			rep(i, d2.size() - 2) {

				vector<int>e{ d2[i],d2[i + 1],d2[i + 2] };

				sort(e.begin(), e.end());

				d1.push_back(e[1]);

			}

			d2 = d1;

			d1.clear();

		}

		if (d2[0] == 5) {

			for (int j : v) {

				cout << j << ' ';

			}

			cout << endl;

		}

		se.insert(d2[0]);

	} while (next_permutation(v.begin(), v.end()));

	for (int i : se) {

		cout << i << endl;

	}*/

	ll n, x; scanf("%lld%lld", &n, &x);

	ll j = 2 * n - 1;

	if (x != 1 && x != j) {

		puts("Yes");

		if (x + j / 2 <= j) {

			for (ll i = x + j / 2; i >= x; i--) {

				printf("%lld\n", i); used[i] = true;

			}

			for (ll i = 1; i <= j; i++) {

				if (!used[i])printf("%lld\n", i);

			}

		}

		else {

			for (ll i = x - j / 2; i <= x; i++) {

				printf("%lld\n", i); used[i] = true;

			}

			for (ll i = j; i >= 1; i--) {

				if (!used[i])printf("%lld\n", i);

			}

		}

	}

	else {

		puts("No");

	}

}