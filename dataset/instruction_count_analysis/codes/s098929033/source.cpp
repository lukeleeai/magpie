#include "stdc++.h"



using namespace std;

typedef long long ll;







int n;

int a[100100];

int md[100100];

int main()

{

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)

    {

        scanf("%d", &a[i]);

    }

    for (int i = 1; i < n; ++i)

    {

        if (a[i] < a[i-1])

        {

            int j = i;

            while (j && a[j] < a[j-1] && md[j-1] < 2)

                --a[j-1],

                ++md[j-1],

                j--;

        }

    }

    bool bla = 1;

    for (int i = 0; i < n-1; ++i)

        if (a[i] > a[i+1] || md[i] > 1) bla = 0;

    if (bla)

        puts("Yes");

    else puts("No");



    return 0;

}
