#include <stdio.h>



int main()

{

    int A,B,C;

    scanf("%d%d%d", &A,&B,&C);

    if (((A == B) && (A != C)  && (B != C)) || ((A == C) && (A != B) && (C != B)) || ((B == C) && (B != A) && (C != A)))

    {

        printf("Yes");

    }

    else {

        printf("No");

    }

    return 0;

}