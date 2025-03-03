#include "stdc++.h"

using namespace std;



#define int long long

typedef pair <int, int> pii;



const int N = 3e5 + 10;

int x, y, z, dpl[N], dpr[N];

multiset <pii> st;



struct ms {

	int a, b, c;

	

	ms() {

		a = b = c = 0;

	}

	

	ms(int x, int y, int z) {

		a = x;

		b = y;

		c = z;

	}

} ar[N];



int32_t main() {

	ios::sync_with_stdio(0);

	cin.tie(0);

	

	cin >> x >> y >> z;

	for (int i = 0; i < x + y + z; i++) {

		int a, b, c;

		cin >> a >> b >> c;

		ar[i] = ms(a, b, c);

	}

	sort(ar, ar + x + y + z, [&] (ms a, ms b) { return a.b + b.c > a.c + b.b; });

	

	int ansx = 0, ansy = 0;

	pii last;

	for (int i = 0; i < y; i++) {

		st.insert({ar[i].a - ar[i].b, ar[i].b});

		ansy += ar[i].b;

	}

	last = *st.rbegin();

	dpl[y - 1] = ansy;

	

	for (int i = y; i < x + y; i++) {

		int tmp = ar[i].a - ar[i].b, ty = ar[i].b;

		if (tmp >= last.first) {

			st.insert({tmp, ty});

			ansx += ar[i].a;

		}

		else {

			st.insert({tmp, ty});

			auto it = st.lower_bound(last);

			assert(it != st.begin());

			it--;

			ansy += ty;

			ansy -= last.second;

			ansx += last.second + last.first;

			last = *it;

		}

		dpl[i] = ansx + ansy;

	}

	

	

	int ansz = 0;

	ansx = 0;

	st.clear();

	for (int i = x + y + z - 1; i >= x + y; i--) {

		st.insert({ar[i].a - ar[i].c, ar[i].c});

		ansz += ar[i].c;

	}

	last = *st.rbegin();

	dpr[x + y] = ansz;

	

	for (int i = x + y - 1; i >= y; i--) {

		int tmp = ar[i].a - ar[i].c, tz = ar[i].c;

		if (tmp >= last.first) {

			st.insert({tmp, tz});

			ansx += ar[i].a;

		}

		else {

			st.insert({tmp, tz});

			auto it = st.lower_bound(last);

			assert(it != st.begin());

			it--;

			ansz += tz;

			ansz -= last.second;

			ansx += last.second + last.first;

			last = *it;

		}

		dpr[i] = ansx + ansz;

	}

	

	

	int ans = 0;

	for (int i = y - 1; i < x + y; i++)

		ans = max(ans, dpl[i] + dpr[i + 1]);

	cout << ans;

}