#include<stdio.h>

long long int b[10000000];

int main()

{

    long long int m,n,T,i,j,sum=0,x,k,cnt=0;

    scanf("%lld %lld",&m,&n);

    for(i=0; i<m; i++)

    {

        scanf("%lld",&T);

        long long int a[T+5],c[T+5];

        for(j=0; j<T; j++)

        {

            scanf("%lld",&a[j]);

            if(a[j]>n)

                scanf("%lld",&a[j]);

        }

        for(j=0; j<T; j++)

        {

            x=1;

            for(k=j+1; k<T; k++)

            {

                if(a[j]==a[k])

                {

                    x++;

                    a[j]=-1;

                }

            }

            if(a[j]!=-1)

            {

                b[a[j]]+=x;

                if(b[a[j]]==m)

                {

                    cnt++;

                }

            }

        }

    }

    printf("%lld\n",cnt);

    return 0;

}
