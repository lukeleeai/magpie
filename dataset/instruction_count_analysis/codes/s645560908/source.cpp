#include <stdio.h>



int main()

{

  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);



  if ((a == c && b == a && b == c) || (a != c && b != a && b != c)) {

    puts("No");

  }

  else

  {

    puts("Yes");

  }

  

  return 0;

}