#include<stdio.h>

int main()

{

    long long n,j;

    while(~scanf("%lld",&n))

    {

        long long ans;

        for(j=1;j*j<=n;j++)

        {

            ans = j*j;

        }

        printf("%lld\n",ans);

    }

    return 0;

}
