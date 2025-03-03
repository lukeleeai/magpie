#include<stdio.h>

#include<string.h>



int main ()

{

    int a,b,c,d,x,y;

    scanf("%d %d %d %d",&a,&b,&c,&d);

    if(a>c) x=a;

    else x=c;

    if(b>d) y=d;

    else y=b;

    if(x>y) printf("0");

    else printf("%d",y-x);

    return 0;

    }