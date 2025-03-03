#include <stdio.h>



int main() {

    long int t, ac = 0, wa = 0, tle = 0, re = 0;

    scanf("%ld", &t);

    for (int i = 0; i < t; i++) {

        char temp[4];

        scanf("%s", &temp);

        switch (temp[0]) {

            case 'A':

                ac++;

                break;

            case 'W':

                wa++;

                break;

            case 'T':

                tle++;

                break;

            case 'R':

                re++;

                break;

        }

    }

    printf("AC x %d\nWA x %d\nTLE x %d\nRE x %d", ac, wa, tle, re);

}