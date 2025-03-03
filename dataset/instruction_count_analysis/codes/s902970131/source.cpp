

#include <cstdio>

#include <cstring>

using namespace std;



typedef unsigned int U;

#define L 1<<21

bool HA[L];

char T[256];



int main() {

    U n, s, t;

    char c;

    T['A'] = (char)1, T['C'] = (char)2, T['G'] = (char)3, T['T'] = (char)4;

    scanf("%d", &n);

    getchar();

    while (n--) {

        s = 0;

        t = 1;

        bool flag = ( c = getchar() ) == 'i';

        while ( ( c = getchar() ) != ' ' );

        while ( ( c = T[getchar()] ) != 0 ) {

            s += c * t;

            t *= 4;

        }

        if ( flag ) {

            HA[s] = true;

        } else {

            puts( HA[s] ? "yes" : "no" );

        }

    }

    return 0;

}