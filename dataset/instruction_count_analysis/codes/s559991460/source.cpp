#include <stdio.h>



int main ()

{

    int K,A,B;

    scanf("%d%d%d",&K,&A,&B);

    if((B/K)*K<A){

        printf("NG\n");

    }

    else{

        printf("OK\n");



    }



    return 0;

}