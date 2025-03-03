#include<stdio.h>

int main()

{

    int a,b,x;

    scanf("%d%d%d",&x,&a,&b);

    printf("%d\n",((x-a)%b));

}