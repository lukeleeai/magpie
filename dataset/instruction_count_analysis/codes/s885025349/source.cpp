#include "stdc++.h"

using namespace std;



void chmin(int& x, int y)

{

  x = min(x, y);

}

void chmax(int& x, int y)

{

  x = max(x, y);

}



int main()

{

  int Q, H, W;

  string S[50];

  int proc = 1;

  int used[50][50] = {{}};



  cin >> Q;

  while(Q--) {

    cin >> H >> W;



    string chars = "";

    for(int i = 0; i < H; i++) {

      cin >> S[i];

      chars += S[i];

    }

    sort(chars.begin(), chars.end());

    chars.erase(unique(chars.begin(), chars.end()), chars.end());

    vector< int > x1(chars.size(), W), x2(chars.size(), 0);

    vector< int > y1(chars.size(), H), y2(chars.size(), 0);

    for(int i = 0; i < H; i++) {

      for(int j = 0; j < W; j++) {

        int pos = chars.find(S[i][j]);

        chmin(x1[pos], j);

        chmax(x2[pos], j);

        chmin(y1[pos], i);

        chmax(y2[pos], i);

      }

    }

    map< char, int > xx1, xx2, yy1, yy2;

    for(int i = 0; i < chars.size(); i++) {

      xx1[chars[i]] = x1[i];

      xx2[chars[i]] = x2[i];

      yy1[chars[i]] = y1[i];

      yy2[chars[i]] = y2[i];

    }



    bool Judge = false;



    do {

      Judge = true;

      for(int i = 0; i < chars.size(); i++) {

        for(int j = xx1[chars[i]]; j <= xx2[chars[i]]; j++) {

          for(int k = yy1[chars[i]]; k <= yy2[chars[i]]; k++) {

            if(used[j][k] == proc) continue;

            used[j][k] = proc;

            if(S[k][j] != chars[i]) {

              Judge = false;

              goto myon;

            }

          }

        }

      }

    myon: ;

      ++proc;

    } while(!Judge && next_permutation(chars.begin(), chars.end()));

    if(Judge) cout << "SAFE" << endl;

    else cout << "SUSPICIOUS" << endl;

  }

}