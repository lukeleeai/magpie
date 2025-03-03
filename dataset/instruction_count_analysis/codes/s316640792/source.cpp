#include"stdc++.h"

using namespace std;



long long calc(int n, int c1, int c2, int s1, int s2, const vector<int>& options,

               int d, int nt, int ot) {

  int b1(d-1), a1(d+1), b2(d-1), a2(d+1);

  while (b1 >= 0 && options[b1] != nt) b1--;

  while (b2 >= 0 && options[b2] != ot) b2--;

  while (a1 < n && options[a1] != nt) a1++;

  while (a2 < n && options[a2] != ot) a2++;

  int x1(d-b1), y1(a1-d), z1(y1-x1), x2(d-b2), y2(a2-d), z2(y2-x2);

  int diff1 = z1*(z1-1)/2-x1*(x1-1)/2-y1*(y1-1)/2;

  int diff2 = z2*(z2-1)/2-x2*(x2-1)/2-y2*(y2-1)/2;

  return (long long) diff1 * c1 - (long long) diff2 * c2 + s1 - s2;

}



int main() {

  int n;

  cin >> n;

  vector<int> c(26);

  vector<array<int, 26>> s(n);

  

  vector<int> last(26, -1);

  

  for (int i = 0; i < 26; ++i)

    cin >> c[i];

  for (int i = 0; i < n; ++i)

    for (int j = 0; j < 26; ++j)

      cin >> s[i][j];

  

  long long total(0);

  vector<int> options(n);

  

  for (int i = 0; i < n; ++i) {

    int neg(0), test(-1);

    for (int j = 0; j < 26; ++j) {

      neg -= c[j] * (i - last[j]);

    }

    

    int max_score = -1e9;

    for (int j = 0; j < 26; ++j) {

      int ss = s[i][j] + neg + c[j] * (i - last[j]);

      if (ss > max_score) {

        max_score = ss;

        test = j;

      }

    }

    total += max_score;

    options[i] = test;

    last[test] = i;

  }

  

  for (int t = 1; t <= 500; ++t) {

    for (int dd = n - 1; dd >= 0; --dd) {

      for (int tt = 25; tt >= 0; --tt) {

        if (tt == options[dd]) continue;

        int ot = options[dd];

        long long ns = calc(n, c[tt], c[ot], s[dd][tt], s[dd][ot],

                            options, dd, tt, ot);

        //cout << ns << endl;

        if (ns > 0) {

          total += ns;

          options[dd] = tt;

    	}

      }

    }

  }

  for (const int& i: options) cout << i + 1 << endl;

  

  return 0;

}