#include <stdio.h>

#include <stdlib.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

#define ABS(a) ((a)>(0)?(a):-(a))



int asc(const void *a, const void *b) {

   return *(int *)a - *(int *)b;

}



int main(void){

   int N,K;

   int L[100000+1];

   int ans = 1000000010;

   scanf("%d%d", &N,&K);

   for (int i = 0; i < N; i++) {

      scanf("%d", &L[i]);

   }

   qsort(L,N,sizeof (int), asc);

   for (int i = 0; i < N - K +1; i++) {

      ans = MIN(ans,ABS(L[i]-L[i+(K-1)]));

   }

   printf("%d\n",ans);

   return 0;

}
