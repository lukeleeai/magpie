#include <iostream>

#include <cstdio>

#include <algorithm>

#define N 100005

using namespace std;



typedef long long ll;

ll n, s, c, a[N];

int main()

{

	ll i;

	cin >> n;

	for (i = 0; i < n; i++) scanf("%lld", &a[i]), s += a[i];

	sort(a, a + n);

	for (i = n - 1; i >= 0; i--) {

		if (s * 2 < a[i + 1]) break;

		s -= a[i];

	}

    cout << n - i - 1 << endl;

    return 0;

}