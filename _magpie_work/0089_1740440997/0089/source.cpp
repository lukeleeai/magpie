#include <stdio.h>

int main(void) {
    int N, i, c;

    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        int k[1000]; // Assuming a maximum size of 1000 for simplicity
        int kk[1000] = {0}; // Initialize the array to 0

        for (i = 0; i < N; i++)
            scanf("%d", &k[i]);

        i = 0, c = 0;

        while (1) {
            if (k[i % N] > 0) {
                k[i % N]--;
                kk[i % N]++;
                c++;
            }
            if (kk[i % N] == 2) {
                printf("%d\n", c);
                break;
            }
            if (i > N * 2) {
                printf("NA\n");
                break;
            }
            i++;
        }
    }

    return 0;
}
