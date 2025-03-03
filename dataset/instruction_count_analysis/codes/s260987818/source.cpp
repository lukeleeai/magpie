#include <stdio.h>

using namespace std;



int main() {

    int N;

    scanf("%d\n", &N);

    int A[N];

    for (int i = 0; i < N; ++i) {

      scanf("%d\n", &A[i]);

    }

 

    int ans = 0;

    while (true) {

        bool odd = false;

        for (int i = 0; i < N; ++i) {

            if (A[i] % 2) odd = true;

        }

        if (odd) break;

        for (int i = 0; i < N; ++i) {A[i] /= 2;}

        ++ans;

    }

    printf("%d\n", ans);

}