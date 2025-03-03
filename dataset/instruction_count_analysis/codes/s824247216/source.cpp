#include <iostream>

#include <string.h>



using namespace std;



#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n) FOR(i,0,n)



int main() {

  cin.tie(0); ios::sync_with_stdio(false);

  char s[100000];

  scanf("%s", s);

  int N = strlen(s);



  REP(a, N) {

    if (a+1 < N && s[a] == s[a+1]) {

      printf("%d %d\n", a+1, a+2);

      return 0;

    } else if (a+2 < N && s[a] == s[a+2]) {

      printf("%d %d\n", a+1, a+3);

      return 0;

    }

  }

  printf("-1 -1\n");



  return 0;

}
