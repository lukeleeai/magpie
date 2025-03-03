#include <string>

#include <iostream>

#include <set>

#include <utility>

using namespace std;

typedef long long ll;



int main(void) {

  ll i, j, k, sm = 1, num, n, las;

  string s, ans;

  cin >> s >> k;

  n = s.size();

  while(sm < n) sm *= 2;

  ll seg[sm * 2];

  set< pair<char, ll> > se;

  for(i = 0; i < sm * 2; ++i) seg[i] = 0;

  num = k + 1 < n ? k + 1 : n;

  las = num;

  for(i = 0; i < num; ++i) se.insert(make_pair(s[i], i));

  ll cnt = 0;

  while(k && ans.size() != n) {

    ++cnt;

    num = k + 1 < n - ans.size() ? k + 1 : n - ans.size();

    while(num > se.size() && las != n) {

      if(seg[sm + las] != -1) se.insert(make_pair(s[las], las));

      las++;

    }

    while(num < se.size()) {

      --las;

      if(seg[sm + las] != -1) se.erase(se.find(make_pair(s[las], las)));

    }

    ans = ans + (*se.begin()).first;

    ll nn = sm + (*se.begin()).second, nnum = (*se.begin()).second;

    while(nn) nnum -= seg[nn], nn /= 2;

    k -= nnum;

    ll now = sm + (*se.begin()).second;

    while( 1 ) {

      while(!(now % 2)) now /= 2;

      if(seg[now] != -1) seg[now]++;

      ll mm = 1;

      while(mm < now) mm *= 2;

      if(mm - now == 1 || now == 1) break;

      now++;

    }

    seg[(*se.begin()).second + sm] = -1;

    set< pair<char, ll> >::iterator it = se.begin();

    it++;

    se.erase(se.begin(), it);

  }

  for(i = 0; i < n; ++i) if(seg[sm + i] != -1) ans = ans + s[i];

  cout << ans << endl;

  return 0;

}
