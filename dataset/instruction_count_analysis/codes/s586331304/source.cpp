#include<stdio.h>

int main()

{

    int a,n,i,j,s,r;

    scanf("%d%d", &n, &a);

    if(n<=a)

        printf("Yes\n");

    else

    {

        if(n%500<=a)

            printf("Yes\n");

        else

            printf("No\n");

    }



}
