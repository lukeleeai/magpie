#include"stdc++.h"

using namespace std;

const int maxn = 2e5 + 7;

long long n, k, d;

int a[maxn], lst[maxn], to[maxn], zz[maxn], t, hs[maxn];



int main() {

	scanf("%lld%lld", &n, &k);

	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

	for (int i = n; i; --i) lst[a[i]] = i;

	for (int i = n; i; --i) {

		to[i] = lst[a[i]];

		lst[a[i]] = i;

	}

	int pos = 1;

	do {

		if(to[pos] <= pos) ++d;

		if(to[pos] == n) ++d;

		pos = to[pos] % n + 1;

	}while(pos != 1);

	k %= d;

	if(k == 0) return 0;

	pos = 1;

	while(1) {

		if(to[pos] <= pos) {

			if(k > 1) --k;

			else break;

		}

		pos = to[pos] % n + 1;

	}

	for (int i = pos; i <= n; ++i) {

		if(hs[a[i]]) {

			//cerr << a[i] << endl;

			while(zz[t] != a[i]) 

				hs[zz[t--]] = 0;

			hs[zz[t--]] = 0;

		}

		else {

			hs[a[i]] = 1;

			zz[++t] = a[i];

		}

	}

	for (int i = 1; i <= t; ++i) printf("%d ", zz[i]);

	printf("\n");

	return 0;

}