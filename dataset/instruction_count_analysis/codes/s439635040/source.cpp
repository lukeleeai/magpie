#include <cstdio>

#include <cstring>



const int MAXN = 2e5 + 10;



char s[MAXN];



int main() {

  int i, j;



  scanf(" %s", s);



  i = 0;

  while (s[i] != 'A') ++i;

  

  j = strlen(s);

  while (s[j] != 'Z') --j;



  printf("%d\n", j - i + 1);

  return 0;

}