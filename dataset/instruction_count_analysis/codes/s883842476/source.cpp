#include <cstdio>

#include <cstdlib>



using namespace std;



int main(void) {



    int n;

    scanf("%d", &n);



    int *arr = static_cast<int*>(malloc(sizeof(int)*n));

    for (int i = 0; i < n; ++i) {

        scanf("%d", &arr[i]);

    }



    int m = 1;

    for (int f = 4; m < 100; ++m, f<<=1) {

        if (n / f == 0)

            break;

    }



    int *G = static_cast<int*>(malloc(sizeof(int)*m));

    G[m-1] = 1;

    for (int i = m - 2, f = 4; i >= 0; --i, f<<=1) {

        G[i] = f;

    }



    int count = 0;

    for (int i = 0; i < m; ++i) {

        int g = G[i];

        for (int j = g; j < n; ++j) {

            int k, key = arr[j];

            for (k = j - g; k >= 0 && arr[k] > key; k-=g, ++count) {

                arr[k + g] = arr[k];

            }

            arr[k+g] = key;

        }

    }



    printf("%d\n", m);

    for (int i = 0; i < m - 1; ++i) {

        printf("%d ", G[i]);

    }

    printf("%d\n", G[m - 1]);

    printf("%d\n", count);

    for (int i = 0; i < n; ++i) {

        printf("%d\n", arr[i]);

    }



    free(arr);

    free(G);



    return 0;

}