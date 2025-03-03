#include<stdio.h>

#include<algorithm>

using namespace std;

int a[200010],b[200010];

main(){

    int n,i,x,y;

    scanf("%d",&n);

    for(i=0;i<n;++i)

    {

        scanf("%d",&a[i]);

        b[i]=a[i];

    }

    sort(b,b+n);

    x=b[(n/2)-1];

    y=b[(n/2)];

    if(x==y)

    {

        for(i=1;i<=n;++i)

        {

            printf("%d\n",x);

        }

    }

    else

    {

        for(i=0;i<n;++i)

        {

            if(a[i]<=x)

            {

                printf("%d\n",y);

            }

            else

            {

                printf("%d\n",x);

            }

        }

    }

}
