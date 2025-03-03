

#include <cstdio>

#include <cstring>

using namespace std;



bool HA[4194304];

int T[256] = {0};



inline int get( unsigned char c ) {

    return T[c];

}



int main() {

    int n, sum, t, c;

    T['A'] = 1, T['C'] = 2, T['G'] = 3, T['T'] = 4;

    while ( scanf("%d", &n) != EOF ) {

        memset( HA, false, 4194304 );

        while ( getchar() != '\n' );

        for ( register int i = 0; i < n; ++ i ) {

            sum = 0;

            t = 1;

            bool flag = ( c = getchar() ) == 'i';

            while ( ( c = getchar() ) != ' ' );

            while ( ( c = T[getchar()] ) != 0 ) {

                sum += c * t;

                t *= 4;

            }

            if ( flag ) {

                HA[sum] = true;

            } else {

                puts( HA[sum] ? "yes" : "no" );

            }

        }

    }

    return 0;

}