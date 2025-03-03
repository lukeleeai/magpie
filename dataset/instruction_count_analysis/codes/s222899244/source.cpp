#include <stdio.h>

using namespace std;



int main() {

  int A,B,king=1;

  scanf("%d %d",&A,&B);

if(A>=1 && A<=13 && B>=1 && B<=13)

{





  if(A==king && B!=1)

  {

      printf("Alice\n");

  }



else if(B==king && A!=1)

{

    printf("Bob\n");



}



else if(A>B)

{

    printf("Alice\n");

}

else if(B>A)

{

    printf("Bob\n");

}

else



     printf("Draw\n");





}



  return 0;

}
