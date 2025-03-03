#include<stdio.h>

int main()

{

    int A,B,C,D;

    scanf("%d%d%d%d",&A,&B,&C,&D);

    if((A+B)>(C+D))printf("Left\n");

    else if((A+B)<(C+D))printf("Right\n");

    else

        printf("Balanced\n");





}