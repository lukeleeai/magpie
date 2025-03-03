#include"stdc++.h"

using namespace std ;

#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )

#define re register

int gi() {

	char cc = getchar() ; int cn = 0, flus = 1 ;

	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }

	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;

	return cn * flus ;

}

const int N = 500 + 5 ;

int n, a[N], b[N * N], Id[N] ; 

bool cmp( int x, int y ) {

	return a[x] < a[y] ;

}

signed main()

{

	n = gi() ;

	rep( i, 1, n ) a[i] = gi(), Id[i] = i ;

	sort( Id + 1, Id + n + 1, cmp ) ;

	rep( i, 1, n ) if( a[Id[i]] == a[Id[i - 1]] ) {

		puts("No") ; exit(0) ;

	}

	int cnt = 0 ;

	rep( i, 1, n ) {

		int u = Id[i] - 1 ; 

		rep( j, 1, u ) {

			while( b[cnt + 1] ) ++ cnt ;

			b[++ cnt] = Id[i] ; 

		} 

		while( b[cnt + 1] ) ++ cnt ;

		if( cnt >= a[Id[i]] ) {

			puts("No") ; exit(0) ;

		}

		b[a[Id[i]]] = Id[i] ; 

		

	}

	rep( i, 1, n ) {

		int u = n - Id[i] ;

		while( b[cnt + 1] ) ++ cnt ; 

		if( cnt < a[Id[i]] ) {

			puts("No") ; exit(0) ; 

		}

		rep( j, 1, u ) {

			while( b[cnt + 1] ) ++ cnt ; 

			b[++ cnt] = Id[i] ;

		}

	}

	printf("Yes\n") ;

	rep( i, 1, n * n ) printf("%d ", b[i] ) ;

	return 0 ;

}