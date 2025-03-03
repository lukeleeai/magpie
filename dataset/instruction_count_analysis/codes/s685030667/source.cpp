#include <cstdio>

 

int main(){

  long a, b, c;

  scanf("%ld %ld.%ld", &a, &b, &c);

  printf("%ld\n", a*(b*100+c)/100);

}