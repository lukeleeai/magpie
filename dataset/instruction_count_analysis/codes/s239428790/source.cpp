#include<cstdio>



int main(){

  int l, r = 0, t = 0;

  scanf("%d", &l);

  for(; (1<<r) <= l; r++) if(l&(1<<r)) t++;

  printf("%d %d\n", r, 2*r+t-3);

  for(int i = 1; i < r; i++){

    printf("%d %d %d\n%d %d %d\n", i, i+1, 1<<(i-1), i, i+1, 0);

    if(l&(1<<(i-1))) printf("%d %d %d\n", i, r, l-=l&-l);

  }

}