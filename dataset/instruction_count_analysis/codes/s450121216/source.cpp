#include <stdio.h>



int main() {

  char ch;

  scanf("%c", &ch);



  if('A' <= ch && ch <= 'Z') {

    puts("A");

  }

  else if('a' <= ch && ch <= 'z') {

    puts("a");

  }

  return 0;

}