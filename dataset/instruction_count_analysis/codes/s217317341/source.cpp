#include <cstdio>

int N;

int h[100005];

int main() {

    scanf("%d",&N);

    h[0] = 0;

    bool flag = true;

    for (int i = 1; i <= N; i++) {

        scanf("%d",&h[i]);

        if (!flag)

            continue;

        if (h[i] >= h[i-1] + 1)

            h[i]--;

        if (h[i] < h[i-1])

            flag = false;

    }

    if (flag)

        printf("Yes\n");

    else

        printf("No\n");

    return 0;

}
