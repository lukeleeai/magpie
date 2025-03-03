#include<stdio.h>

#include<stdlib.h>

int main()

{

    int a,b,c,d;

    scanf("%d%d%d%d",&a,&b,&c,&d);

    if((abs(a-b))<=d&&(abs(b-c))<=d)

        {

            printf("Yes");

        }

    else if((abs(a-c))<=d)

        {

            printf("Yes");

        }

    else

        {

            printf("No");

        }





    return 0;



}
