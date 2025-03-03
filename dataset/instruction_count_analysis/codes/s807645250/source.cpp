#include <cstdio>

#include <algorithm>

using namespace std;



int main()

{

    int n;

    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)

    {

        scanf("%d", &a[i]);

    }

    sort(a, a + n);

    int c = 1, ans = 0;

    for (int i = 0; i < n; i++)

    {

        if (a[i] == a[i + 1])

        {

            c++;

        }

        if (a[i] != a[i + 1])

        {

            if (c % 2 == 0)

            {

                ans--;

                c = 1;

            }

            if (c % 2 == 1)

            {

                ans++;

                c = 1;

            }

        }

    }

    printf("%d\n", ans);

}