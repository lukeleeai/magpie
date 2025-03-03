#include <cstdio>

#include <queue>

#include <cstring>



using namespace std;



int w, h;

char a[555][555];



int main(void) {

  scanf("%d%d", &h, &w);

  for (int i = 0; i < h; i++) {

    for (int j = 0; j < w; j++) {

      scanf(" %c", a[i]+j);

    }

  }



  for (int i = 0; i < h; i++) {

    for (int j = 0; j < w; j++) {

      printf("%c", i == 0 || a[i][j] == '#' || (i!=h-1&&j%2 == 0) ? '#' : '.');

    }

    puts("");

  }



  puts("");

  

  for (int i = 0; i < h; i++) {

    for (int j = 0; j < w; j++) {

      printf("%c", i == h-1 || a[i][j] == '#' || (i!=0&&j%2 == 1) ? '#' : '.');

    }

    puts("");

  }

  

  return 0;

}
