#include <cstdio>

#include <cstring>

#include <vector>

#include <queue>

#include <algorithm>

#include <cmath>

#include <cassert>

#include <utility>

#include <set>

#include <map>

using namespace std;



typedef pair<int, int> ii;

typedef long long ll;



ll n, T;

const int maxn = 2e5+1;

ll t[maxn];



int main()

{

  scanf("%lld %lld", &n, &T);

  for (int i = 0; i < n; ++i)

    scanf("%lld", t+i);

  sort(t, t+n);

  ll ans = T;

  for (int i = 1; i < n; ++i)

    {

      ans += min(T, t[i]-t[i-1]);

    }

  printf("%lld\n", ans);

}
