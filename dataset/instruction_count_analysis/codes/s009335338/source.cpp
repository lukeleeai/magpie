#include<stdio.h>

int main()

{

    int i,j,n,s=0,m,x,p,min,max=0;

    scanf("%d%d", &n,&x);

    int a[n+5];

    for(i=0;i<n;i++)

    {

        scanf("%d", &a[i]);

        s=s+a[i];

        if(a[i]>max)

            max=a[i];

    }

    x=x-s;

    min=max;

    for(i=0;i<n;i++)

    {

        if(a[i]<min)

            min=a[i];

    }

    p=x/min;

    p=p+n;

    printf("%d\n", p);

}
