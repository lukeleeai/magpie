#include <stdio.h>



static int a[200'000];



int main() {

    int n;

    scanf("%u", &n);

  

  	auto xor_total = 0;

    for (auto i = 0; i < n; i += 2) {

        scanf("%u %u", &a[i], &a[i + 1]);

        xor_total ^= (a[i] ^ a[i + 1]);

    }

    for (auto i = 0; i < n; i += 2) {

        printf("%u %u ", xor_total ^ a[i], xor_total ^ a[i + 1]);

    }



    return 0;

}
