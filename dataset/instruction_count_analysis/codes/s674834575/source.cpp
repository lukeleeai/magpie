#include "stdc++.h"



using namespace std;



const int INF = 1 << 30;



int main()

{

  int N;

  string S;



  cin >> S;





  int sz[100001] = {}, sz2[100001] = {};

  for(int i = (int) S.size() - 1; i >= 0; i--) {

    sz[i] = sz[i + 1];

    if(S[i] == 'g') ++sz[i];

    else --sz[i];

  }



  int goo = 0, ret = -INF;

  int lost = 0;

  for(int i = 0; i < S.size(); i++) {

    if(S[i] == 'g') ++goo;

    else if(S[i] == 'p' && goo == 0) ++lost;

    else --goo;

    ret = max(ret, -lost + min(goo, sz[i + 1]));

  }

  cout << ret << endl;

}