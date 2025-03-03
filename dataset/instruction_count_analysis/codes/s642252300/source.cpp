#include <stdio.h>

int main(void)

{

  int h,w;

  char a[101][101];

  scanf("%d%d",&h,&w);

  for(int i=0; i<h; i++)

    scanf("%s",a[i]);

  

  for(int i=0; i<w+2; i++)

    printf("#");

  puts("");

  

  for(int i=0; i<h; i++)

    printf("#%s#\n",a[i]);

  

  for(int i=0; i<w+2; i++)

    printf("#");

  puts("");

  

  return 0;

}