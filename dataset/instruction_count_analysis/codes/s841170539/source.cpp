#include <cstdio>

using namespace std;



using i64 = long long;



#define REP(i, stop) for (int i = 0, i##_len = stop; i < i##_len; ++i)



const int cm = 1 << 17;

char cn[cm], *ci = cn + cm, ct;

inline char getc() {

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int read() {

	int r = 0;

	if (ci - cn + 16 > cm) while ((ct = getc()) & 16) r = r * 10 + ct - '0';

	else while ((ct = *ci++) & 16) r = r * 10 + ct - '0';

	return r;

}



// x shoud be greater than or equal to zero

inline void write(i64 x) {

	char d[20];

	int i = 0;

	while (true) {

		d[i] = x % 10 + 48;

		x /= 10;

		++i;

		if (x <= 0) break;

	}

	while (i--) {

		putchar(d[i]);

	}

}



int A[100001];

signed main() {

	int n = read();

	REP(i, n + 1) {

		A[i] = read();

	}

	i64 s = 0;

	int a0;

	int a1 = A[0];

	REP(i, n) {

		a0 = a1;

		a1 = A[i + 1];

		int b = read();

		int m = a0 < b ? a0 : b;

		s += m;

		b -= m;

		m = a1 < b ? a1 : b;

		s += m;

		a1 -= m;

	}

	write(s);

}
