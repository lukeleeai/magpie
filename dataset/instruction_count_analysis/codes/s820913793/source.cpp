#include <stdio.h>



int main() {

    char a;

    scanf("%c", &a);

    if (a >= 'A' && a <= 'Z') puts("A");

    else if (a >= 'a' && a <= 'z') puts("a");

    return 0;

}
