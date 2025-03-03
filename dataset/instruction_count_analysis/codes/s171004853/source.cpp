#include<stdio.h>

int main()

{

    int a,b,t,sum=0;

    scanf("%d%d%d",&a,&b,&t);

    int num;

    num=t/a;

    sum=sum+num*b;

    printf("%d\n",sum);

    return 0;

}