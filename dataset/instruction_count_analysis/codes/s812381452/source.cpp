#include <stdio.h>



int main() {

  int line, store1, store2;

  scanf("%d %d %d", &line, &store1, &store2);

  int distA = (line > store1) ? line - store1 : store1 - line;

  int distB = (line > store2) ? line - store2 : store2 - line;

  (distA < distB) ? puts("A") : puts("B");

  return 0;

}