#include <cstdio>

using namespace std;



bool solve(int n, int a[], int i, int m) {

    if (m == 0) {

        return true;

    }

    if (i >= n) {

        return false;

    }

    return solve(n, a, i + 1, m - a[i]) || solve(n, a, i + 1, m);

}



int main() {

    int n;

    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {

        scanf("%d", &a[i]);

    }

    int q;

    scanf("%d", &q);

    int m;

    for (int i = 0; i < q; i++) {

        scanf("%d", &m);

        if (solve(n, a, 0, m)) {

            printf("yes\n");

        } else {

            printf("no\n");

        }

    }



    return 0;

}
