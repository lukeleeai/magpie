#include <cstdio>

#include <cmath>



typedef long long   signed int LL;

typedef long long unsigned int LU;



#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)

#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)

#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)

#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)

#define inc( i, n) incID(i, 0, n)

#define inc1(i, n) incII(i, 1, n)

#define dec( i, n) decID(i, 0, n)

#define dec1(i, n) decII(i, 1, n)



#define inII(v, l, r) ((l) <= (v) && (v) <= (r))

#define inID(v, l, r) ((l) <= (v) && (v) <  (r))



template<typename T> void swap(T & x, T & y) { T t = x; x = y; y = t; return; }

template<typename T> T abs(T x) { return (0 <= x ? x : -x); }

template<typename T> T max(T a, T b) { return (b <= a ? a : b); }

template<typename T> T min(T a, T b) { return (a <= b ? a : b); }

template<typename T> bool setmin(T & a, T b) { if(a <= b) { return false; } else { a = b; return true; } }

template<typename T> bool setmax(T & a, T b) { if(b <= a) { return false; } else { a = b; return true; } }

template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }

template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }



// ---- ----



int n, eor, a[100];

const int MOD = 1000000007;

int dp[101][256][101];



LL f(LL x) {

	if(x == 0) { return 1; }

	return (x * f(x - 1)) % MOD;

}



int main() {

	scanf("%d%d", &n, &eor);

	inc(i, n) { scanf("%d", &a[i]); }

	

	dp[0][0][0] = 1;

	inc(i, n) {

		inc(j, 256) {

		inc(k,   n) {

			(dp[i + 1][j][k] += dp[i][j][k]) %= MOD;

			(dp[i + 1][ j ^ a[i] ][k + 1] += dp[i][j][k]) %= MOD;

		}

		}

	}

	

	LL ans = 0;

	inc1(k, n) {

		(ans += f(k) * dp[n][eor][k]) %= MOD;

	}

	

	printf("%d\n", ans);

	

	return 0;

}
