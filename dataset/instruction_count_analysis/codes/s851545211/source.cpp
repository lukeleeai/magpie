#include<stdio.h>

int main()

{

    int n,i;

    scanf("%d",&n);

    if(n%2==0)

    printf("%d\n",n);

    else if((n*2)%2==0)

        printf("%d\n",n*2);

}