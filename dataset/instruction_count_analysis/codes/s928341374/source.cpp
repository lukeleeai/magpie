#include <stdio.h>



int main() {

    int i, x, y, a[200001];

    long long int tmp;



    scanf("%d%d", &x, &y);

    

    for (i = 0; i < x; i++) {

        scanf("%d", a + i);

    }



    for (i = y; i < x; i++) {

        if (a[i] >a[i - y]) {

            printf("Yes\n");

        } else {

            printf("No\n");

        }

    }

    

}