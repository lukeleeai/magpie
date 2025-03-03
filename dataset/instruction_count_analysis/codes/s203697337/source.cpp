#include <cstdio>



bool hasElement(int s[], int n, int t) {

    int left = 0, right = n;

    while (left < right) {

        int mid = (left + right) / 2;

        if (s[mid] == t) {

            return true;

        }

        if (s[mid] < t) {

            left = mid + 1;

        } else {

            right = mid;

        }

    }

    return false;

}



int main() {

    int n, q;

    scanf("%d", &n);

    int s[n];

    for (int i = 0; i < n; i++) {

        scanf("%d", &s[i]);

    }

    scanf("%d", &q);

    int c = 0;

    for (int i = 0; i < q; i++) {

        int t;

        scanf("%d", &t);

        if (hasElement(s, n, t)) {

            c++;

        }

    }

    printf("%d\n", c);



    return 0;

}
