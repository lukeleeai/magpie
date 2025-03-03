#include <iostream>

#include <map>



using namespace std;



#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n) FOR(i,0,n)

#define IN(v) int v;cin>>v;

#define OUT(v) cout<<v<<"\n"



const int MAX_N = 1e5;



string s;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

map<char, int> occurrence[MAX_N+1];



int main() {

  cin.tie(0); ios::sync_with_stdio(false);

  cin >> s;



  REP(i, s.length()) {

    REP(j, 26) {

      occurrence[i+1][alphabet[j]] = occurrence[i][alphabet[j]];

    }

    occurrence[i+1][s[i]] = occurrence[i][s[i]] + 1;

  }

  REP(a, s.length()) {

    if (a+1 < s.length() && s[a] == s[a+1]) {

      OUT(a + 1 << " " << a + 2);

      return 0;

    } else if (a+2 < s.length() && s[a] == s[a+2]) {

      OUT(a + 1 << " " << a + 3);

      return 0;

    }

  }

  OUT(-1 << " " << -1);



  return 0;

}
