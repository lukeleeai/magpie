#include<stdio.h>

int main()

{

    int x;

    scanf("%d",&x);

    int a[x+10],i,j,cnt=0;

    for(i=0;i<x;i++)

    {

        scanf("%d",&a[i]);

    }

    for(i=1;i<x-1;i++)

    {

       if(a[i]>a[i-1])

       {

           if(a[i]<a[i+1])cnt++;

       }

       else if(a[i]<a[i-1])

       {

           if(a[i]>a[i+1])cnt++;

       }

    }

    printf("%d",cnt);

}