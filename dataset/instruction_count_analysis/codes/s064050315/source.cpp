#include "stdc++.h"

using namespace std;



int n;

double d0, d;



int main() {

	double ans = 0.0;

	cin >> n >> d0 >> d;

	n = n << 1;

	d0 -= d;

	for( ; n >= 2; n -= 2 ) {

		ans += d0 + d * (n + 1) / 2.0;

		double nd0 = d0 + (2 * d0 + 3 * d) / n;

		double nd = d + (4 * d) / n;

		d0 = nd0, d = nd;

	}

	cout << setprecision(20) << fixed << ans << endl;

}




