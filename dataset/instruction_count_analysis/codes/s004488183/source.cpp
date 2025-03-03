#include <vector>

#include <list>

#include <map>

#include <set>

#include <deque>

#include <stack>

#include <bitset>

#include <algorithm>

#include <functional>

#include <numeric>

#include <utility>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <cstdlib>

#include <cctype>

#include <string>

#include <cstring>

#include <ctime>

using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)

#define repe(i,n) for(int i = 0; i <= (int)(n); i++)

typedef vector<int> VI; typedef vector<VI> VVI;

typedef vector<string> VS; typedef vector<VS> VVS;

typedef pair<int, int> PII;

typedef long long LL;





int main(){

  LL sum = 0;

  VI num(1000000, 0);

  int i = 0;

  string s;

  cin >> s;



  while (i != (s.size())) {

    int a = 0, b = 0, j = 0;



    if (s[i] == '<')  { 

      while (s[i] == '<') { a++; i++; }

      for (j = (i-a); j <= i; j++) num[j] += j - (i-a);

    } else  { 

      while (s[i] == '>') { b++; i++; } 

      for (j = i; j >= (i-b); j--) {

        num[j] = (i - j);

      }

      j++;

      if (j != 0 && num[j] <= num[j-1]) num[j] = (num[j-1] + 1);

    }

  }



  //cout << num[0];

  //rep(i, s.size()) {

  //  cout << " " << s[i] << " " << num[i+1];

  //}

  //cout << endl;



  rep(i,s.size()+1) {

    sum += num[i];

  }

  cout << sum << endl;

  return 0;

}
