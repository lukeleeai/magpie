#include <stdio.h>



int main() {

  int t, k;

  scanf ("%d %d", &t, &k);

  int nilai[t];



  for (int i = 0; i < t; i++) {

    scanf("%d", &nilai[i]);

  }

    

  for (int i = 0; i < t-k; i++) {

    (nilai[i] < nilai[i+k]) ? puts("Yes") : puts("No");

  }

    

  return 0;

}