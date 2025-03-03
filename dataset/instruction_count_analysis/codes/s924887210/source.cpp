#include <stdio.h>

#include <utility>

#include <string.h>



int main(void) {

  int i, j, k, n, sm = 1, now, num = 0, tmp, befnum;

  char s[200010], ans[200010];

  scanf("%s", s);

  scanf("%d", &k);

  n = strlen(s);

  for(i = 0; i <= n; ++i)ans[i] = 0;

  while(sm < n) sm *= 2;

  std::pair<char, int> seg[sm * 2];

  int seg2[sm * 2], las[sm * 2];

  int ss = 2;

  for(i = 0; i < sm * 2; ++i) {

    seg2[i] = 0;

    if(ss <= i) ss *= 2;

    las[i] = sm / (ss / 2) * (i - ss / 2 + 1);

    if(i == 1) las[i] = sm;

  }

  for(i = 0; i < sm; ++i) {

    seg[i + sm].first = s[i], seg[i + sm].second = i;

    if(i % 2) {

       now = i + sm;

       now /= 2;

       while(now) seg[now] = seg[now * 2] > seg[now * 2 + 1] ? seg[now * 2 + 1] : seg[now * 2], now /= 2;

    }

  }

  tmp = befnum = k + 1 > n ? n : k + 1;

  while(num != n && k) {

    //printf("%s %d %d %d %d\n", ans, num, tmp, befnum, k);

    i = tmp;

    if(befnum < k + 1) {for(i = tmp; i < n && befnum < k + 1; ++i) if(seg[i + sm].first != 'z' + 1) befnum++;while(seg[i + sm].first == 'z' + 1) ++i;}

    else if(befnum > k + 1) {for(i = tmp; i >= 0 && befnum > k + 1; --i) if(seg[i + sm].first != 'z' + 1) befnum--; while(seg[i + sm].first == 'z' + 1) --i;}

    tmp = i;

    std::pair<char, int> min = std::make_pair('z' + 1, 100);

    now = 1;

    while( 1 ) {

      while(las[now] > tmp) now *= 2;

      if(seg[now] < min) min = seg[now];

      if(las[now] == tmp) break;

      now++;

    }

    ans[num] = min.first;

    num++;

    int d = min.second;

    now = sm + min.second;

    seg[now].first = 'z' + 1;

    d -= seg2[now];

    now /= 2;

    while(now) d -= seg2[now], seg[now] = seg[now * 2] > seg[now * 2 + 1] ? seg[now * 2 + 1] : seg[now * 2], now /= 2;

    k -= d;

    befnum--;

    now = sm + min.second;

    while( 1 ) {

      while(!(now % 2)) now /= 2;

      seg2[now]++;

      if(las[now] == sm) break;

      now++;

    }

  }

  for(i = 0; i < n; ++i) if(seg[i + sm].first != 'z' + 1) ans[num] = s[i], num++;

  printf("%s\n", ans);

  return 0;

}
