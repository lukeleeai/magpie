#include<stdio.h>

int main() {

  int N;

  scanf("%d", &N);

  for(int i=1; i<=100; i++){ 

    N=N-2;

    if(N<=0){

      printf("%d", i);

      break;

    }else{

    }



  }

  return 0;

}