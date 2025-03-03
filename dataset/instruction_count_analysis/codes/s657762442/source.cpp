#include <stdio.h>





int main () {

    int n;

    scanf("%d", &n);

    char echo[n + 1];

    scanf("%s", echo);

    if (n % 2 == 1) {

        puts("No");

    }

    else {

        int flag = 1;

        for (int i = 0; i < n / 2; i++){

            if (echo[i] != echo[i + n / 2]){

                flag = 0;

            }

        }

        if (flag){

            puts("Yes");

        }

        else {

            puts("No");

        }

    }

    return 0;

}