#include "stdc++.h"



using namespace std;



const int N = 1e5 + 5;

int sparse[N][18], n, a[N], l, q;



int get (int x, int y) {

    int ans = 1;

    for (int i = 17; i >= 0; i--) {

        if (sparse[x][i] != -1 && sparse[x][i] < y) {

            x = sparse[x][i];

            ans = ans + (1 << i);

        }

    }



    return ans;

}



int main(){

    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    scanf("%d", &l);

    scanf("%d", &q);



    memset(sparse, -1, sizeof(sparse));

    for (int i = 0; i < n; i++) sparse[i][0] = upper_bound(a, a + n, a[i] + l) - a - 1;

    for (int j = 1; j < 18; j++) {

        for (int i = 0; i < n; i++) {

            if (sparse[i][j - 1] != -1) sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];

        }

    }



    while (q--) {

        int x, y;

        scanf("%d %d", &x, &y);

        if (x > y) swap(x, y);

        printf("%d\n", get(x - 1, y - 1));

    }

    return 0;

}
