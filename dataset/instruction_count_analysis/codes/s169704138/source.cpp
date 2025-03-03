#include <stdio.h>

int main()

{

    int N;

    scanf("%d",&N);

    if((N%10==2)||(N%10==4)||(N%10==5)||(N%10==7)||(N%10==9))

    {

        printf("hon\n");

    }

    else if((N%10==0)||(N%10==1)||(N%10==6)||(N%10==8))

    {

        printf("pon\n");

    }

    else if(N%10==3)

    {

        printf("bon\n");

    }

}