#include<stdio.h>

int main()

{

    int a,b,s,m,p;

    scanf("%d%d",&a,&b);

    s=a+b,p=a*b,m=a-b;

    a=(s>p?(s>m?s:m):(p>m?p:m));

    printf("%d\n",a);



}