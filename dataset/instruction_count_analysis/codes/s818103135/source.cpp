#include "stdc++.h"

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

typedef pair<int, int> P;



int n;

P robots[101010];



int main(){

  cin >> n;

  rep(i, n){

    int x, l;

    cin >> x >> l;

    robots[i].second = x - l;

    robots[i].first = x + l;

  }

  sort(robots, robots + n);

  //rep(i, n) cerr << robots[i].second << " " << robots[i].first << endl;

  int pos = -1000000000;

  int ans = 0;

  for(P x : robots){

    if(x.second >= pos){

      pos = x.first;

      ans++;

    }

  }

  cout << ans << endl;

  return 0;

}
