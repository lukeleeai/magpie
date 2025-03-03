#include <stdio.h>



int main() {

    int abc;

    int a;

    int b;

    

    scanf("%d", &abc);

    scanf("%d %d", &a, &b);

    while(a <= b) {

        if(a%abc == 0) {

            printf("OK");

            return 0;

        }

        a++;

    }

    printf("NG");

    

    return 0;

}