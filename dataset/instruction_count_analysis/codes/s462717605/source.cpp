#include <stdio.h>



int main()

{

    long long N, n, h, w;

    scanf("%lld", &N);

    int flag = 0;

    for(n = 1; n <= 3500; n++)

    {

        for(h = 1; h <= 3500; h++)

        {

            long long u = N * n * h;

            long long d = 4 * h * n - N * h - N * n;

            if(d > 0 && u % d == 0)

            {

                w = u / d;

                flag = 1;

                break;

            }

        }

        if(flag)

            break;

    }

    printf("%lld %lld %lld\n", h, n, w);

    return 0;

}
