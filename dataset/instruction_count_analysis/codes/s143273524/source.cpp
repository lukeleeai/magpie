#include "stdc++.h"



using namespace std;



int main()

{

  int n, m, l[200000], r[200000];

  vector< int > line[100001];



  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; i++) l[i] = r[i] = i;

  while(m--) {

    int x, y;

    scanf("%d %d", &x, &y);

    line[x].push_back(y);

  }

  for(int i = 0; i < 100000; i++) {

    for(auto &p : line[i]) {

      l[p] = l[p - 1];

      r[p - 1] = r[p];

    }

  }

  for(int i = 0; i < n; i++) {

    if(i > 0) putchar(' ');

    printf("%d", r[i] - l[i] + 1);

  }

  putchar('\n');

}