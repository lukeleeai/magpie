#include <iostream>

#include <sstream>

using namespace std;



int main() {

  int H, W;

  cin >> H >> W;

  string a[55][55];

  for (int i=0; i<H; i++) {

    string str;

    cin >> str;

    for (int j=0; j<W; j++) {

      a[i][j] = str[j];

    }

  }



  const int dx[4] = { 1, 0, -1, 0 };

  const int dy[4] = { 0, 1, 0, -1 };



  string b[55][55];

  for (int i=0; i<H; i++) {

    for (int j=0; j<W; j++) {

      if (a[i][j] == "#") {

        int num = 0;

        for (int d = 0; d < 4; ++ d) {

          const int ni = i + dy[d];

          const int nj = j + dx[d];

          if (ni < 0 or H <= ni) continue;

          if (nj < 0 or W <= nj) continue;

          if (a[ni][nj] == "#") {

            num = 1;

            break;

          }

        }

        b[i][j] = char(num + '0');

      } else {

        b[i][j] = ".";

      }

    }

  }

  string result;

  for (int i=0; i<H; i++) {

    for (int j=0; j<W; j++) {

      if (b[i][j] == "0") {

        result = "No";

        goto OUT;

      } else {

        result = "Yes";

      }

    }

  }

  OUT: cout << result << endl;

  return 0;

}
