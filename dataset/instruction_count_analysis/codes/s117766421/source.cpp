#include <cstdio>

#include <algorithm>



int main() {

  int N;

  scanf("%d %*d", &N);



  int min=1e9+1;

  int maxprofit=0, res=0;

  for (int i=0; i<N; ++i) {

    int A;

    scanf("%d", &A);



    if (A < min)

      min = A;



    if (A - min == maxprofit) {

      ++res;

    } else if (A - min > maxprofit) {

      maxprofit = A - min;

      res = 1;

    }

  }



  printf("%d\n", res);

  return 0;

}
