#include "stdc++.h"



using namespace std;

typedef long long ll;



#define REP(i,n) for(ll i=0;i<(ll)(n);i++)

#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)

#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)

#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)

#define ALL(x) (x).begin(),(x).end()

#define SIZE(x) ((ll)(x).size())

#define MAX(x) *max_element(ALL(x))

#define SUM(x) accumulate(ALL(x), 0)

#define INF 1000000000000

#define MOD 10000007

#define PB push_back

#define MP make_pair

#define F first

#define S second

#define MAXR 100000



int main()

{

  int h, w; cin >> h >> w;

  vector<vector<char>> s(h, vector<char>(w));

  REP(i, h) {

    string s_; cin >> s_;

    REP(j, w) {

      s.at(i).at(j) = s_[j];

    }

  }



  int bk; int wh;

  REP(i, h) {

    REP(j, w) {

      if (s.at(i).at(j) == '.') wh++;

      else bk++;

    }

  }



  if (wh == h * w) {

    cout << "Yes" << endl;

    return 0;

  }



  int cnt = 0;

  REP(i, h) {

    REP(j, w) {

      if (s.at(i).at(j) == '.') continue;

      if (i == 0) {

        if (j == 0) {

          if (s.at(i + 1).at(j) == '#' || s.at(i).at(j + 1) == '#') cnt++;

        } else if (j == w - 1) {

          if (s.at(i + 1).at(j) == '#' || s.at(i).at(j - 1) == '#') cnt++;

        } else {

          if (s.at(i + 1).at(j) == '#' || s.at(i).at(j - 1) == '#' || s.at(i).at(j + 1) == '#') cnt++;

        }

      } else if (i == h - 1) {

        if (j == 0) {

          if (s.at(i - 1).at(j) == '#' || s.at(i).at(j + 1) == '#') cnt++;

        } else if (j == w - 1) {

          if (s.at(i - 1).at(j) == '#' || s.at(i).at(j - 1) == '#') cnt++;

        } else {

          if (s.at(i - 1).at(j) == '#' || s.at(i).at(j - 1) == '#' || s.at(i).at(j + 1) == '#') cnt++;

        }

      } else {

        if (j == 0) {

          if (s.at(i - 1).at(j) == '#' || s.at(i + 1).at(j) == '#' || s.at(i).at(j + 1) == '#') cnt++;

        } else if (j == w - 1) {

          if (s.at(i - 1).at(j) == '#' || s.at(i + 1).at(j) == '#' || s.at(i).at(j - 1) == '#') cnt++;

        } else {

          if (s.at(i - 1).at(j) == '#' || s.at(i + 1).at(j) == '#' || s.at(i).at(j - 1) == '#' || s.at(i).at(j + 1) == '#') cnt++;

        }

      }

    }

  }



  if (cnt == bk) {

    cout << "Yes" << endl;

  } else {

    cout << "No" << endl;

  }

  return 0;

}
