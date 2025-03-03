#include "stdc++.h"

using namespace std;



using ll = long long;

using ii = pair<int,int>;



const int N = 1e5+10;



int n;

char s[N];



int main() { 

  scanf("%s", s);

  n = strlen(s);

  int j = (n - 1) / 2;

  while(j + 1 < n && s[j + 1] == s[(n - 1) / 2]) j++;

  int ans = j + 1;

  j = (n - 1) / 2;

  while(j - 1 >= 0 && s[j - 1] == s[(n - 1) / 2]) j--;

  ans = min(ans, n - j);

  printf("%d\n", ans);

  return 0;

}
