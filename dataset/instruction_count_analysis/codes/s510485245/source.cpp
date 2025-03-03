#include<stdio.h>

int main(void)

{

  int A,B,C,D,x;

  x=scanf("%d %d %d %d",&A,&B,&C,&D);

  while(!0)

  {

    C-=B;if(C<=0)return printf("Yes"),0;

    A-=D;if((A<=0))return printf("No"),0;

  }

}