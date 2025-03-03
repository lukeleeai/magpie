// Why am I so dumb? :c

#include"stdc++.h"



#define pb push_back

#define mp make_pair



#define all(x) (x).begin(), (x).end()



#define fi first

#define se second



using namespace std;



typedef long long ll;



int a[55], b[55];



int n;



bool bit(ll x, int p) {

	return x & (1ll << p);

}



bool check(ll m) {

	for (int i = 1; i <= n; ++i) {

		ll cur = (1ll << a[i]);



		for (int j = 50; j > 0; --j) {

			if (bit(m, j)) {

				for (int p = 0; p < j; ++p) {

					if (!bit(cur, p)) {

						for (int nx = p + j; nx <= 50; nx += j) {

							if (bit(cur, nx)) {

								cur |= (1ll << p);

								break;

							}

						}

					}

				}                

			}			

		}



		if (!bit(cur, b[i])) {

			return 0;

		}

	}	



	return 1;

}



void solve() {

	scanf("%d", &n);



	for (int i = 1; i <= n; ++i) {

		scanf("%d", &a[i]);

	}



	for (int i = 1; i <= n; ++i) {

		scanf("%d", &b[i]);

	}



	ll mask = (1ll << 51) - 2ll;



	if (!check(mask)) {

		printf("-1\n");

		return;

	}



	for (int i = 50; i > 0; --i) {

		mask -= (1ll << i);



		if (!check(mask)) {

			mask += (1ll << i);

		}

	}



	printf("%lld\n", mask);

}



int main() {

    int tt = 1;



    while (tt--) {

        solve();

    }



    return 0;

}