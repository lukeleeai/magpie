#include<stdio.h>

int main(void)

{

  int A,B,C,K;

  if(scanf("%d %d %d %d",&A,&B,&C,&K)==4)

  {

    if(A>=K)return printf("%d\n",K),0;

    else if(B>=K-A)return printf("%d\n",A),0;

    else return printf("%d\n",2*A+B-K),0;

  }

}