#include<stdio.h>

int main()

{

    int n;scanf("%d",&n);

    int a[n+10],i,j,count=0;

    for(i=0;i<n;i++)

    {

        scanf("%d",&a[i]);

    }

    for(i=1;i<n-1;i++)

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

}
