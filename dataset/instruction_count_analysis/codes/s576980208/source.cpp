#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

typedef long long ll;



const int MAX_N = 200000;



ll cnt = 0ll;

int n;

ll K, a[MAX_N + 10], s[MAX_N + 10], b[MAX_N + 10], t[MAX_N + 10];



void merge_sort(ll* A, int x, int y, ll* T) {

    if (y - x > 1) {

        int m = x + (y - x) / 2;

        int p = x, q = m, i = x;

        merge_sort(A, x, m, T);

        merge_sort(A, m, y, T);

        while (p < m || q < y) {

            if (q >= y || (p < m && A[p] <= A[q])) T[i++] = A[p++];

            else { T[i++] = A[q++]; cnt += m - p; }

        }

        for (i = x; i < y; i++) A[i] = T[i];

    }

}



int main() {

    scanf("%d%lld", &n, &K);

    for (int i = 0; i < n; i++) {

        scanf("%lld", &a[i]);

        s[i] = a[i] + (i ? s[i - 1] : 0);

        b[i] = (i ? s[i - 1] : 0) - K * i;

    }

    b[n] = s[n - 1] - n * K;

    merge_sort(b, 0, n + 1, t);

    printf("%lld\n", (ll)n * (n + 1) / 2 - cnt);

    return 0;

}