#include<stdio.h>

int main()

{

  int A,B;

  char S[10],T[10],U[10];

  scanf("%s %s\n%d %d\n%s",S,T,&A,&B,U);



  if(*S==*U)

  {

    printf("%d %d\n", A-1, B);

  }

  else if(*T==*U)

  {

    printf("%d %d\n", A,B-1);

  }

  return 0;

}
