#include<stdio.h>

#include<string.h>

int main()

{

    int X,Y;



    char S[20];

    char T[20];

    char U[20];



    scanf("%s %s",S,T);

    scanf("%d %d",&X,&Y);

    scanf("%s",U);





    if(strcmp(S,U)==0)

    {





    X--;

    printf("%d %d",X,Y);

    }





  else

    {



    Y--;

    printf("%d %d",X,Y);

    }



    return 0;

}
