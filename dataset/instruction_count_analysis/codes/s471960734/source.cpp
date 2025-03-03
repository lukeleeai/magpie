#include "stdc++.h"

#define reg register

using namespace std;

const int MAXN = 2e5 + 10;

int n;

int a[MAXN];

int main() {

    scanf("%d", &n);

    for(reg int i = 1; i <= n; ++i)

        scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);

    for(reg int i = 1; i <= n; ++i) {

        if(a[i] == a[i + 1]) {

            puts("NO");

            return 0;

        }

    }

    puts("YES");

    return 0;

}
