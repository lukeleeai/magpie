#include "stdc++.h"

using namespace std;



const int N = 55;



string s[N];

int cnt[26];



int main() {

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int n; cin >> n;

  for (int i = 0; i < n; i++) {

    cin >> s[i];

  }

  for (int i = 0; i < (int)s[0].size(); i++) {

    cnt[s[0][i] - 'a']++;

  }

  for (int i = 1; i < n; i++) {

    int curcnt[26];

    for (int j = 0; j < 26; j++) curcnt[j] = 0;

    for (int j = 0; j < (int)s[i].size(); j++) {

      curcnt[s[i][j] - 'a']++;

    }

    for (int j = 0; j < 26; j++) {

      cnt[j] = min(cnt[j], curcnt[j]);

    }

  }

  vector<char> v;

  for (int i = 0; i < 26; i++) {

    for (int j = 0; j < cnt[i]; j++) {

      v.push_back(i + 'a');

    }

  }

  sort(v.begin(), v.end());

  for (char c : v) cout << c;

  cout << endl;

  return 0;

}
