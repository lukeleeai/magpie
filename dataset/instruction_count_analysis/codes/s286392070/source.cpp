#include "stdc++.h"



#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define int long long



using namespace std;

typedef long long ll;



const int maxn = 1e5 + 5, inf = 2e9;



class node

{

public:

  int Max, Min, pos;

  ll sum;

  node(int _Max = 0, int _Min = 0, int _pos = 0, ll _sum = 0)

  {

    Max = _Max; Min = _Min; pos = _pos; sum = _sum;

  }

  node operator + (const node & other) const

  {

    node res;

    res.Max = max(Max, other.Max);

    res.Min = min(Min, other.Min);

    res.sum = sum + other.sum;

    res.pos = (Max < other.Max) ? other.pos : pos;

    return res;

  }

}ST[4 * maxn];

int lazy[4 * maxn];

ll res[maxn];

int N, a[maxn];



#define lc id << 1

#define rc id << 1 | 1

void build(int id, int l, int r)

{

  lazy[id] = -1;

  if (l == r){

    ST[id].sum = ST[id].Max = ST[id].Min = a[l];

    ST[id].pos = l;

    return;

  }

  int mid = (l + r) / 2;

  build(lc, l, mid); build(rc, mid + 1, r);

  ST[id] = ST[lc] + ST[rc];

}



void dolazy(int id, int l, int r)

{

  if (lazy[id] != -1){

    ST[id].Max = ST[id].Min = lazy[id];

    ST[id].sum = 1ll * (r - l + 1) * lazy[id];

    ST[id].pos = l;

    if (l != r){

      lazy[lc] = lazy[id];

      lazy[rc] = lazy[id];

    }

  }

}



void update(int id, int l, int r, int L, int R, int val)

{

  dolazy(id, l, r);

  if (l > R || L > r || L > R) return;

  if (l == r){

    if (ST[id].Min >= val) ST[id] = node(val, val, l, val);

    else{



    }

    return;

  }

  if (L <= l && r <= R){

    if (ST[id].Min >= val){

      lazy[id] = val;

      ST[id].Max = ST[id].Min = val;

      ST[id].sum = (r - l + 1) * val;

      ST[id].pos = l;

      if (l != r){

        lazy[lc] = val;

        lazy[rc] = val;

      }

      return;

    }

  }

  int mid = (l + r) / 2;

  update(lc, l, mid, L, R, val); update(rc, mid + 1, r, L, R, val);

  ST[id] = ST[lc] + ST[rc];

}



ll query(int id, int l, int r, int L, int R, int val)

{

  dolazy(id, l, r);

  if (l > R || L > r || L > R) return 0;

  if (l == r){

    if (ST[id].Min >= val) return ST[id].Min - val;

    return 0;

  }

  if (L <= l && r <= R){

    if (ST[id].Min >= val){

      return ST[id].sum - 1ll * (r - l + 1) * val;

    }

  }

  int mid = (l + r) / 2;

  return query(lc, l, mid, L, R, val) + query(rc, mid + 1, r, L, R, val);

}



node getsum(int id, int l, int r, int L, int R)

{

  dolazy(id, l, r);

  if (l > R || L > r || L > R) return node(-inf, inf);

  if (L <= l && r <= R){

    return ST[id];

  }

  int mid = (l + r) / 2;

  return getsum(lc, l, mid, L, R) + getsum(rc, mid + 1, r, L, R);

}



signed main(void)

{

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  if (fopen("A.INP", "r")){

    freopen("A.INP", "r", stdin);

    freopen("A.OUT", "w", stdout);

  }

  cin >> N;

  for (int i = 1; i <= N; ++i){

    cin >> a[i];

  }

  build(1, 1, N);

  int pos = getsum(1, 1, N, 1, N).pos;

  while (true){

    int np = getsum(1, 1, N, 1, pos - 1).pos;

    res[pos] = query(1, 1, N, pos, N, a[np]);

    update(1, 1, N, pos, N, a[np]);

    if (pos == 1) break;

    pos = np;

  }

  for (int i = 1; i <= N; ++i){

    cout << res[i] << '\n';

  }

}
