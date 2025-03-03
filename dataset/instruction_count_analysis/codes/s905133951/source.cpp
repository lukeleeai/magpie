#include "stdc++.h"

using namespace std;



using ll = long long;



#define int long long



#define REP(i, n) for (int i = 0; i < (n); ++i)

#define SIZE(a) ((int)(a).size())



string brucik(int a, int b, int c, int d) {

	int n = a + b;

	pair<int,string> rs;

	rs = {n + 1, ""};

	REP(mask, 1<<n) {

		int ca, cb;

		ca = cb = 0;

		int mx = 0, last = -1, cur = 0;

		string curS;

		REP(i, n) {

			int bit = (mask >> i) & 1;

			if (bit) ++cb; else ++ca;

			if (bit) curS += 'B'; else curS += 'A';

			if (bit != last) cur = 0;

			++cur;

			last = bit;

			mx = max(mx, cur);

		}

		if (ca != a || cb != b) continue;

		pair<int,string> here = {mx, curS};

		rs = min(rs, here);

	}

	return rs.second.substr(c, d-c+1);

}



string solve(int a, int b, int c, int d) {

	int rv = 0;

	// brucik(a, b, c, d);

	if (a < b) {

		swap(a, b);

		c = a + b - c - 1;

		d = a + b - d - 1;

		swap(c, d);

		rv = 1;

	}

	string result;

	int r = (a + b) / (b + 1);

	if (r == 1) {

		for (int i = c; i <= d; ++i) {

			result += i % 2 ? 'B' : 'A';

		}

	} else {

		int x = (r*(a+1)-b-1)/(r*r-1);

		int y = ((a-r*x+1)*r - (b-x))/r;

		x *= r+1;

		y += x;

		for (int i = c; i <= d; ++i) {

			int now = i;

			if (now < x) {

				result += now % (r + 1) == r ? 'B' : 'A';

			} else 

			if (now < y) {

				result += 'A';

			} else {

				now -= y;

				now = a + b - now - 1;

				now -= y;

				result += now % (r + 1) == r ? 'A' : 'B';

			}

		}

	}

	if (rv) {

		reverse(result.begin(), result.end());

		for (auto& c : result) c = 'A' + 'B' - c;

	}

	return result;

}



main() {

	ios::sync_with_stdio(false);

	cin.tie(0);



	// cout << solve(11, 9, 0, 19) << endl;

	// cout << brucik(11, 9, 0, 19) << endl;



	// for (int a = 1; a <= 12; ++a) {

	// 	for (int b = 1; b <= 12; ++b) {

	// 		if (solve(a, b, 0, a + b - 1) != brucik(a, b, 0, a + b - 1)) {

	// 			cout << a << ' ' << b << endl;

	// 			cout << solve(a, b, 0, a + b - 1) << ' ' << brucik(a, b, 0, a + b - 1) << endl;

	// 			return 0;

	// 		}

	// 	}

	// }



	int t;

	cin >> t;

	REP(i, t) {

		int a, b, c, d;

		cin >> a >> b >> c >> d;

		--c; --d;

		cout << solve(a, b, c, d) << '\n';

	}



	return 0;

}