#include <stdio.h>



typedef long long ll;



/////////////         modの計算

const ll mod = 1000000007LL;



class modlong {

public:

	modlong() { x = 0; }

	modlong(ll num) { x = num; }

	inline operator ll() const { return x; }

	inline void operator = (ll num) { x = num; }

	inline void operator += (ll num) { x = adjust(x + num); }

	inline void operator *= (ll num) { x = adjust(x * num); }

	inline modlong operator * (ll num) { modlong m(adjust(this->x * num)); return m; }

private:

	inline ll adjust(ll a) {

		if (a >= mod) { return a % mod; }

		return a;

	}

	ll x;

};



constexpr int K = 16;



constexpr ll v_e[] = { 0, 765144583, 346175634, 347662323, 5655049, 184117322, 927321758, 444014759, 542573865, 237315285, 417297686, 471090892, 183023413, 660103155, 727008098, 869418286 };

constexpr ll v_o[] = { 539588932, 729548371, 700407153, 404391958, 962779130, 184117322, 927321758, 444014759, 542573865, 237315285, 417297686, 471090892, 183023413, 660103155, 727008098, 869418286 };



int main() {

	int T; scanf("%d", &T);

	for (int _t = 0; _t < T; _t++) {

		ll N; scanf("%ld", &N);

		modlong ans = 0;

		modlong x = 1;



		if (N & 1) {// odd

			for (int i = 0; i < K; i++) {

				ans += x * v_o[i];

				x *= N;

			}

		}

		else {// even

			for (int i = 0; i < K; i++) {

				ans += x * v_e[i];

				x *= N;

			}

		}

		printf("%ld\n", ans);

	}



	return 0;

}
