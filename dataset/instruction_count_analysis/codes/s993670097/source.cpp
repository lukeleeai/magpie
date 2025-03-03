#include <stdio.h>



int main() {

  int z, A, B;

  scanf("%d %d %d", &z, &A, &B);

  int distA = (z > A) ? z - A : A - z;

  int distB = (z > B) ? z - B : B - z;

  (distA < distB) ? puts("A") : puts("B");

  return 0;

}