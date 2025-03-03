#include <iostream>

#include <cstdio>

#include <algorithm>

#include <cstring>

#include <string>

#include <map>

using namespace std;

int A[200005], c[200005];

int main()

{

    int n;

    while(~scanf("%d", &n))

    {

        memset(c, 0, sizeof(c));

        int ans = 0, m = 0, a, a2, b, b2;

        for(int i = 1; i <= n; i++)

        {

            scanf("%d", &A[i]);

            m = max(m, A[i]);

        }

        int tmpa = 0, tmpa2 = 0, tmpb = 0, tmpb2 = 0;

        for(int i = 1; i <= n; i += 2)

            c[A[i]]++;

        for(int i = 1; i <= m; i++)

        {

            if(c[i] > tmpa)

            {

                swap(tmpa2, tmpa);

                swap(a, a2);

                tmpa = c[i];

                a = i;

            }

            else if(c[i] > tmpa2)

            {

                tmpa2 = c[i];

                a2 = i;

            }

        }

        memset(c, 0, sizeof(c));

        for(int i = 2; i <= n; i += 2)

            c[A[i]]++;

        for(int i = 1; i <= m; i++)

        {

            if(c[i] > tmpb)

            {

                swap(tmpb2, tmpb);

                swap(b, b2);

                tmpb = c[i];

                b = i;

            }

            else if(c[i] > tmpb2)

            {

                tmpb2 = c[i];

                b2 = i;

            }

        }

        if(a == b)

        {

            ans = n - max(tmpa + tmpb2, tmpb + tmpa2);

        }

        else

            ans = n - tmpa - tmpb;

        printf("%d\n", ans);

    }

    return 0;

}
