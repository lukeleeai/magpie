#include "stdc++.h"



using namespace std;



int main(){

  int n;cin >> n;

  string s; cin >> s;

  int cnt = 0;

  for(int i = 0; i < n; ++i){

    if(s[i] == '#')cnt++;

  }

  int ans = cnt;

  for(int i = n - 1; i >= 0; --i){

    if(s[i] == '#')cnt--;

    else cnt++;

    ans = min(ans, cnt);

  }

  cout << ans << endl;

}
