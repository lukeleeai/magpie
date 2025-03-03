#include<stdio.h>

int main()

{

    int k;

    scanf("%d",&k);

    int a[k+10],i,count=0;

    for(i=0;i<k;i++)

    {

        scanf("%d",&a[i]);

    }

    for(i=1;i<k-1;i++)

    {

       if(a[i]>a[i-1])

       {

           if(a[i]<a[i+1])count++;

       }

       else if(a[i]<a[i-1])

       {

           if(a[i]>a[i+1])count++;

       }

    }

    printf("%d",count);

    return 0;

}