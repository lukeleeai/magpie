#include "stdc++.h"

using namespace std;

typedef long long   signed int LL;

typedef long long unsigned int LU;

#define incII(i, l, r) for(int i = (l)    ; i <= (r); ++i)

#define incID(i, l, r) for(int i = (l)    ; i <  (r); ++i)

#define decII(i, l, r) for(int i = (r)    ; i >= (l); --i)

#define decID(i, l, r) for(int i = (r) - 1; i >= (l); --i)

#define inc(i, n)  incID(i, 0, n)

#define inc1(i, n) incII(i, 1, n)

#define dec(i, n)  decID(i, 0, n)

#define dec1(i, n) decII(i, 1, n)

#define inII(v, l, r) ((l) <= (v) && (v) <= (r))

#define inID(v, l, r) ((l) <= (v) && (v) <  (r))

#define PB push_back

#define EB emplace_back

#define MP make_pair

#define FI first

#define SE second

#define  ALL(v)  v.begin(),  v.end()

#define RALL(v) v.rbegin(), v.rend()

template<typename T> bool setmin  (T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }

template<typename T> bool setmax  (T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }

template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }

template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }

LL mo(LL a, LL b) { assert(b > 0); a %= b; if(a < 0) { a += b; } return a; }

LL fl(LL a, LL b) { assert(b > 0); return (a > 0 ? a / b : (a - b + 1) / b); }

LL ce(LL a, LL b) { assert(b > 0); return (a < 0 ? a / b : (a + b - 1) / b); }

#define bit(b, i) (((b) >> (i)) & 1)

#define BC __builtin_popcountll

#define SC(T, v) static_cast<T>(v)

#define SI(v) SC(int, v.size())

#define SL(v) SC( LL, v.size())

#define RF(e, v) for(auto & e: v)

#define ei else if

#define UR assert(false)



// ---- ----



int n, q, d[200000];

string s, t;



bool g(int p) {

	inc(i, q) {

		if(t[i] == s[p]) { p += d[i]; }

		if(p == -1) { return true; }

		if(p == n) { break; }

	}

	return false;

}



int f() {

	int L = -1, H = n;

	while(H - L > 1) {

		int M = (L + H) / 2;

		(g(M) ? L : H) = M;

	}

	return H;

}



int main() {

	cin >> n >> q >> s;

	inc(i, q) {

		string T, D;

		cin >> T >> D;

		t += T;

		d[i] = (D == "L" ? -1 : +1);

	}

	

	int ans = n;

	ans -= f();

	reverse(ALL(s));

	inc(i, q) { d[i] *= -1; }

	ans -= f();

	

	cout << ans << endl;

	

	return 0;

}
