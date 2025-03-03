#include<stdio.h>



int main()

{

    int a[309][309], n;

    while(~scanf("%d", &n))

    {

        for(int i = 1; i <= n; i++)

            for(int j = 1; j <= n; j++)

                scanf("%d", &a[i][j]);

        long long ans = 0;

        for(int i = 1; i <= n; i++)

        {

            for(int j = 1; j < i; j++)

            {

                bool flag = 1;

                for(int k = 1; k <= n; k++)

                {

                    if(a[i][j] > a[i][k] + a[k][j])

                    {

                        printf("-1\n");

                        return 0;

                    }

                    else if(i != k && k != j && a[i][j] == a[i][k] + a[k][j])

                        flag = 0;

                }

                if(flag)

                    ans += a[i][j];

            }

        }

        printf("%lld\n", ans);

    }

    return 0;

}
