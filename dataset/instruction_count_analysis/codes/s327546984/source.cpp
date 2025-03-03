#include"stdc++.h"

#define MAX 100005

using namespace std;

 

int main(){

  int n, mn = 0, t = 0, u = 0;

  string s;

  cin >> n >> s;

  for(int i = 1; i < n; i++){

    t += (s[i-1] == 'W') + (s[i] == 'W') - 1;

    u += (s[i] == 'E');

    mn = min(mn, t);

  }

  printf("%d\n", u+mn);

}