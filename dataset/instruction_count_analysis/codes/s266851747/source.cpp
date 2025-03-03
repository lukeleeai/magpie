#include <iostream>

#include <algorithm>

#include <iomanip>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#include <vector>

#include <string>

#include <queue>

#include <deque>

#include <list>

#include <set>

#include <unordered_set>

#include <map>

#include <unordered_map>

#include <bitset>

#include <random>

#include <complex>

#include <assert.h>



using namespace std;

typedef long long ll;

#define endl '\n'



/////////////         modの計算



#define MOD_IS_PRIME

const ll mod = 1000000007LL;



class modlong {

public:

	modlong() { x = 0; }

	modlong(ll num) { x = adjust(num); }

	inline operator ll() const { return x; }

	inline bool operator ==(ll num) { return this->x == num; }

	inline bool operator !=(ll num) { return !(*this == num); }

	inline void operator = (ll num) { x = adjust(num); }

	inline void operator += (ll num) { x = adjust(x + num); }

	inline void operator ++() { this->operator+=(1); }

	inline modlong operator + (ll num) const { modlong m(this->x); m += num; return m; }

	inline void operator -= (ll num) { x = adjust(x - num); }

	inline void operator --() { this->operator-=(1); }

	inline modlong operator - (ll num) { modlong m(this->x); m -= num; return m; }

	inline void operator *= (ll num) { x = adjust(x * num); }

	inline modlong operator * (ll num) { modlong m(this->x); m *= num; return m; }

private:

	inline ll adjust(ll a) {

		if (a >= mod) { return a % mod; }

		if (a < 0) { return mod - 1 + ((a + 1) % mod); }

		return a;

	}

	ll x;

};



int main() {

	ios::sync_with_stdio(false);

	std::cin.tie(0);



	constexpr int K = 16;



	vector<modlong> v_e = { 0, 765144583, 346175634, 347662323, 5655049, 184117322, 927321758, 444014759, 542573865, 237315285, 417297686, 471090892, 183023413, 660103155, 727008098, 869418286 };

	vector<modlong> v_o = { 539588932, 729548371, 700407153, 404391958, 962779130, 184117322, 927321758, 444014759, 542573865, 237315285, 417297686, 471090892, 183023413, 660103155, 727008098, 869418286 };



	int T; cin >> T;

	for (int _t = 0; _t < T; _t++) {

		ll N; cin >> N;

		if (N % 2 == 0) {// even

			modlong ans = 0;

			modlong x = 1;

			for (int i = 0; i < K; i++) {

				ans += x * v_e[i];

				x *= N;

			}

			cout << (ll)ans << endl;

		}

		else {// odd

			modlong ans = 0;

			modlong x = 1;

			for (int i = 0; i < K; i++) {

				ans += x * v_o[i];

				x *= N;

			}

			cout << (ll)ans << endl;

		}

	}



	return 0;

}