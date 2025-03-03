#include "stdc++.h"



# define Size 1000000



inline int readInt ( )  {

    register int x, c ;

    static char buf [Size], *ss, *tt ;

    # define pick( ) ( (ss == tt) ? ( tt = buf + fread ( ss = buf, 1, Size, stdin ), ( ss == tt ) ? -1 : *ss ++ ) : *ss ++ )

    while ( ! isdigit ( c = pick ( ) ) ) ;

    for ( x = -48 + c ; isdigit ( c = pick ( ) ) ; x = x * 10 + c - 48 ) ;

    return x ;

    # undef pick

}



inline void smin ( long long& d, long long x )  {  ( d > x ) ? d = x : 0 ;  }



const long long inf = ( ~0ull >> 1 ) ;

const int N = 200010 ;



int q [N] ;

bool inq [N] ;

long long a [N] ;



struct edge  {

    int to, w ; edge* nxt ;

} g [N], *head [N], *NewEdge ;



int main ( )  {

    int h, w, n ;

    h = readInt ( ), w =  readInt ( ), n = readInt ( ) ;

    NewEdge = g ;

    for ( int i = 0 ; i < n ; ++ i )  {

        int x = readInt ( ), y = readInt ( ), z = readInt ( ) ;

        -- x, -- y ;

        *( ++ NewEdge ) = ( edge ) {  h + y, z, head [x]  } ; head [x] = NewEdge ;

        *( ++ NewEdge ) = ( edge ) {  x, z, head [h + y]  } ; head [h + y] = NewEdge ;

    }

    for ( int i = 0, l = h + w ; i < l ; ++ i )  {

        if ( ! inq [i] )  {

            register edge* it ;

            register int fr ( 0 ), tl ( 0 ) ;

            a [i] = 0 ;

            q [++ tl] = i ;

            inq [i] = true ;

            while ( fr ^ tl )  {

                int u = q [++ fr] ;

                for ( it = head [u] ; it ; it = it -> nxt )  {

                    int r = it -> to, v = it -> w ;

                    if ( inq [r] )  {

                        if ( a [u] + a [r] != v )  {

                            return puts ( "No" ), 0 ;

                        }

                        continue ;

                    }

                    q [++ tl] = r ;

                    inq [r] = true ;

                    a [r] = v - a [u] ;

                }

            }

            long long m1 = inf, m2 = inf ;

            while ( tl )  {

                ( q [tl] < h ) ? smin ( m1, a [q [tl --]] ) : smin ( m2, a [q [tl --]] ) ;

            }

            if ( m1 + m2 < 0 )  {

                return puts ( "No" ), 0 ;

            }

        }

    }

    return puts ( "Yes" ), 0 ;

}