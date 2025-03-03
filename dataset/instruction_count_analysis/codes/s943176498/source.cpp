#include <stdio.h>

#include <string.h>



int main() {

    long long int input; 

	long long int modulo;

    char nama[55];

    scanf("%lld", &input);

    int i = 0;

    while (input > 0) {

        modulo = (input - 1) % 26;

        nama[i++] = 'a' + modulo;

        input = (input - modulo) / 26;

    }

    nama[i] = '\0';

    int panjang = strlen(nama);

    for (panjang--; panjang >= 0; panjang--) {

        printf("%c", nama[panjang]);

    }

return 0;    

}
