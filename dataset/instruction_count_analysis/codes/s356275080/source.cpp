#include <stdio.h>



using namespace std;

#define MAX(a,b) (a>b?a:b)

int main(){

  int num, cap;

  scanf("%d %d", &num,&cap);

  int itens[num+1][2];

  for (size_t i = 1; i < num+1; i++) {

      scanf("%d %d",itens[i],itens[i]+1);

    // printf("%d %d\n",itens[i][0],itens[i][1]);

  }

  num++,cap++;

  long long parciais[num][cap];

  for (size_t i = 0; i < cap; i++) {

    parciais[0][i] = 0;

  }

  for (size_t i = 1; i < num; i++) {

    for (size_t j = 0; j < cap; j++) {

      if(j < itens[i][0])

        parciais[i][j] = parciais[i-1][j];

      else

        parciais[i][j] = MAX(parciais[i-1][j],(long long)itens[i][1] + parciais[i-1][j-itens[i][0]]);

    }

  }

  // printf("   ");

  // for (size_t i = 0; i < num; i++) {

  //   printf("qtd%d            ", i);

  // }

  // printf("\n");

  // printf("\n");

  // for (size_t i = 0; i < cap; i++) {

  //   printf("%d  ", i);

  //   for (size_t j = 0; j < num; j++) {

  //     printf("%02lld              ", parciais[j][i]);

  //   }

  //   printf("\n\n");

  // }



  num--,cap--;

  printf("%lld\n",parciais[num][cap]);

}
