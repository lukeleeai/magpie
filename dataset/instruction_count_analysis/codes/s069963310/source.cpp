#include <map>

#include <cmath>

#include <cstdio>

#include <iostream>



typedef long long LL;

#define int LL



const int MAXN = 1e5, MAXFAC = 2155;

const LL MAXV = 1e10;

int n, pn, pr[MAXFAC + 5], siz[MAXN + 5], rev[MAXN + 5];

LL val[MAXN + 5];

bool vis[MAXFAC + 5];

std::map<LL, int> buc;



inline LL rint () {

	LL x = 0; char s = getchar ();

	for ( ; s < '0' || '9' < s; s = getchar () );

	for ( ; '0' <= s && s <= '9'; s = getchar () ) x = x * 10 + ( s ^ '0' );

	return x;

}



inline void sieve ( const int n ) {

	for ( int i = 2; i <= n; ++ i ) {

		if ( ! vis[i] ) pr[++ pn] = i;

		for ( int j = 1; j <= pn && i * pr[j] <= n; ++ j ) {

			vis[i * pr[j]] = true;

			if ( ! ( i % pr[j] ) ) break;

		}

	}

}



inline bool issqr ( const LL x ) {

	LL t = pow ( x, 1.0 / 3 );

	return t * t * t == x || ( t + 1 ) * ( t + 1 ) * ( t + 1 ) == x;

}



signed main () {

	n = rint (), sieve ( MAXFAC );

	int ans = 0;

	for ( int i = 1; i <= n; ++ i ) {

		LL a = rint ();

		if ( issqr ( a ) ) { ans = 1; continue; }

		LL cur = 1, mtc = 1;

		for ( int j = 1; j <= pn && pr[j] <= a; ++ j ) {

			int cnt = 0;

			for ( ; ! ( a % pr[j] ); a /= pr[j], ++ cnt );

			if ( ! ( cnt %= 3 ) ) continue;

			cur *= pr[j], mtc *= pr[j];

			if ( cnt == 1 ) mtc *= pr[j];

			else cur *= pr[j];

			if ( mtc > MAXV ) mtc = 0;

		}

		LL sqt = sqrt ( a );

		cur *= a;

		if ( sqt * sqt == a || ( sqt + 1 ) * ( sqt + 1 ) == a ) mtc *= sqt;

		else {

			mtc *= a;

			if ( mtc > MAXV ) mtc = 0;

			mtc *= a;

		}

		if ( mtc > MAXV ) mtc = 0;

		if ( ! buc.count ( cur ) ) siz[buc[cur] = i] = 1, rev[i] = mtc;

		else ++ siz[buc[cur]];

		val[i] = cur;

	}

	for ( int i = 1; i <= n; ++ i ) {

		if ( ! siz[i] ) continue;

		if ( ! buc.count ( rev[i] ) ) {

			ans += siz[i], siz[i] = 0;

		} else {

			ans += std::max ( siz[i], siz[buc[rev[i]]] );

			siz[i] = siz[buc[rev[i]]] = 0;

		}

	}

	printf ( "%lld\n", ans );

	return 0;

}