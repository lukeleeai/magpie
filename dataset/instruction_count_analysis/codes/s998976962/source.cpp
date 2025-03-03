#include"stdc++.h"

using namespace std;

 

int main(){

  int l, r, t = 0;

  scanf("%d", &l);

  for(r = 0; (1<<r) <= l; r++); r--;

  for(int i = l; i; i -= i&-i, t++); t--;

  printf("%d %d\n", r+1, 2*r+t);

  for(int i = 0; i < r; i++){

    printf("%d %d %d\n", i+1, i+2, 1<<i);

    printf("%d %d %d\n", i+1, i+2, 0);

    if(l&(1<<i)) printf("%d %d %d\n", i+1, r+1, l-=l&-l);

  }

}