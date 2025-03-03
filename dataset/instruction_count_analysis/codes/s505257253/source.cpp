#include <stdio.h>

int main(void){

    int L; scanf("%d", &L);

    int n = 0; while((1 << (n+1)) <= L) n++;

    int N = (1 << n) - 1; int U = L - N - 1;

    int l = L;

    int m = 2 * n + __builtin_popcount(U);

    printf("%d %d\n", n+1, m);

    for(int x = 0; x + 1 <= n; ++x) printf("%d %d 0\n%d %d %d\n", x+1, x+2, x+1, x+2, (1 << x));

    for(int d = n; d >= 0; --d) if((U >> d) & 1){

        l -= (1 << d);

        printf("%d %d %d\n", d+1, n+1, l);

    }

    return 0;

}