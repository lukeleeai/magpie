#include "stdc++.h"

using namespace std;



int main() {

  ios::sync_with_stdio(false);

  cin.tie(0);

  

  string S;

  cin >> S;



  int size = S.length();

  vector<int> vi(size + 1);

  for (int i = 0; i < size; i++) {

    if (S[i] == '<') {

      vi[i + 1] = vi[i] + 1;

    }

  }



  reverse(vi.begin(), vi.end());

  for (int i = 0; i < size; i++) {

    if (S[size - (i + 1)] == '>') {

      if (vi[i] >= vi[i + 1]) {

        vi[i + 1] = vi[i] + 1;

      }

    }

  }



  long long res = 0;

  for (int i = 0; i < vi.size(); i++) {

    res += vi[i];

  }

  cout << res << '\n';

}
