#include <stdio.h>



int main() {

    int n;

    scanf("%d", &n);



    int c = 0;

    for (int i = 1; i <= n; i+=2) {

        int y = 0;

        for (int j = 1; j <= i; j++) {

            if (i % j == 0) { 

                y++;

            }

        }

        if (y== 8) {

            c++;

        }

    }



    printf("%d\n", c);

}


