#include <stdio.h>

#include <algorithm>



typedef long long LLONG;



int main(void) {

  LLONG L, R;

  scanf(" %lld %lld", &L, &R);

  

  LLONG min = 2020;

  

  LLONG endNum = std::min(R, L + 2019);

  for(LLONG l = L; l < endNum; l++) {

    LLONG ans = 0;

    for(LLONG r = l + 1; r <= endNum; r++) {

    	ans = (l * r) % 2019;

      	min = std::min(min, ans);

    }

  }

  

  printf("%lld\n", min);

}