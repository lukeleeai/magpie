

#include "stdc++.h"



#define ln                 '\n'

#define all(dat)           dat.begin(), dat.end()

#define loop(i, to)        for (int i = 0; i < to; ++i)

#define cont(i, to)        for (int i = 1; i <= to; ++i)

#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)

#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)



typedef long long          num;



using namespace std;



const int nsz = 2e5;

const num inf = 0x3f3f3f3f3f3f3f3f;

int n, l[nsz + 5], r[nsz + 5];

num d, a[nsz + 5], ans;



num inline w1(int id) {

	return a[id] - d * id;

}



num inline w2(int id) {

	return a[id] + d * id;

}



num inline w(int u, int v) {

	return a[u] + a[v] + d * abs(u - v);

}



int main() {

	scanf("%d%lld", &n, &d);

	cont (i, n) {

		scanf("%lld", &a[i]);

	}

	a[0] = inf, a[n + 1] = inf;

	cont (i, n) {

		l[i] = w1(l[i - 1]) < w1(i) ? l[i - 1] : i;

	}

	for (int i = n; i >= 1; --i) {

		r[i] = w2(r[i + 1]) < w2(i) ? r[i + 1] : i;

	}

	int pre = 0;

	cont (i, n) {

		if (l[i] == i && r[i] == i) {

			if (pre)  ans += w(pre, i);

			pre = i;

		} else {

			ans += min(l[i] != i ? w(l[i], i) : inf, r[i] != i ? w(i, r[i]) : inf);

		}

	}

	cout << ans << ln;

}