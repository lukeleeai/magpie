#include <cstdio>

#include <cstring>

bool matrix[105][105];

int arr[105];

int brr[105];

int N;

int main() {

    scanf("%d",&N);

    memset(matrix, true, sizeof(matrix));

    int sum = (N*(N+1)) / 2;

    int base, e;

    printf("%d\n",N*(N-1)/2 - N/2);

    if (N % 2) {

        base = N;

        e = N - 1;

    } else {

        base = N + 1;

        e = N;

    }



    for (int i = 1; i <= e; i++) {

        matrix[i][base - i] = matrix[base - i][i] = false;

    }

     for (int i = 1; i <= N; i++) {

        for (int j = 1; j <= N; j++) {

            if (i == j || !matrix[i][j])

                continue;

            printf("%d %d\n",i, j);

            matrix[i][j] = matrix[j][i] = false;

        }

    }

    return 0;

}
