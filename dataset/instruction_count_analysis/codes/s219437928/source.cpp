#include <cstdio>

int main() {

    int n = 0, t = 0, tot = 0, maxLen = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%d", &t);

        if (t > maxLen)

            maxLen = t;

        tot += t;

    }

    printf((maxLen * 2 < tot) ? "Yes" : "No");

    return 0;

}